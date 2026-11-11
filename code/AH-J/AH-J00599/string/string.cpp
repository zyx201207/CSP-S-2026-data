#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long len;
struct node{
    long long len;
    char c;
    long long l,r;
}a[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].c;
        a[i].l=len+1;
        a[i].r=a[i].l+a[i].len-1;
        len+=a[i].len;
    }
    if(len%2==0){
        long long hwf=len/2;
        long long sum=0;
        for(int i=1;i<=n;i++){
            if(sum+a[i].len>=hwf){
                if(sum==hwf){
                    break;
                }else if(sum+a[i].len==hwf){
                    break;
                }else{
                    for(int j=n+1;j>i+1;j--){
                        a[j]=a[j-1];
                    }
                    a[i+1].l=hwf+1;
                    a[i+1].r=a[i].r;
                    a[i+1].c=a[i].c;
                    a[i+1].len=a[i+1].r-a[i+1].l+1;
                    a[i].r=hwf;
                    a[i].len=a[i].r-a[i].l+1;
                    n++;
                }
                break;
            }
            sum+=a[i].len;
        }
    }else{
        long long hwf=(len+1)/2;
        long long sum=0;
        for(int i=1;i<=n;i++){
            if(sum+a[i].len>=hwf){
                if(sum+1==hwf){
                    a[i].l++;
                    a[i].len--;
                }else if(sum+a[i].len==hwf){
                    a[i].r--;
                    a[i].len--;
                }else{
                    for(int j=n+1;j>i+1;j--){
                        a[j]=a[j-1];
                    }
                    a[i+1].l=hwf+1;
                    a[i+1].r=a[i].r;
                    a[i+1].c=a[i].c;
                    a[i+1].len=a[i+1].r-a[i+1].l+1;
                    a[i].r=hwf-1;
                    a[i].len=a[i].r-a[i].l+1;
                    n++;
                }
                break;
            }
            sum+=a[i].len;
        }
    }
    long long ans=0;
    int l=1,r=n;
    long long xbl=1,xbr=len;
    while(l<r){
        if(a[l].r-xbl+1>xbr-a[r].l+1){
            if(a[l].c!=a[r].c){
                ans+=xbr-a[r].l+1;
            }
            xbl+=xbr-a[r].l+1;
            if(xbl==a[l+1].l){
                l++;
            }
            xbr=a[r-1].r;
            r--;
        }else{
            if(a[l].c!=a[r].c){
                ans+=a[l].r-xbl+1;
            }
            xbr-=a[l].r-xbl+1;
            if(xbr==a[r-1].r){
                r--;
            }
            xbl=a[l+1].l;
            l++;
        }
    }
    cout<<ans;
    return 0;
}
