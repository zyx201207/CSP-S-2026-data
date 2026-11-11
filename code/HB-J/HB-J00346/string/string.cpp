#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200010];
char c[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if(n<=10){
        int flag=0;
        string l="";
        int num =0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>c[i];
            if(i>1&&c[i]!=c[i-1]){
                flag=1;
            }
            for(int j=1;j<=a[i];j++){
                l+=c[i];
            }
        num+=a[i];
        }
        if(flag==0){
            cout<<0;
            return 0;
        }
        cout<<l;
        int len=l.size(),sum=0,r=len-1;
        for(int i=0;i<len/2;i++){
            if(l[i]!=l[r]){
                sum++;
            }
            r--;
        }
        cout<<sum;
        return 0;
    }
    int flag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(i>1&&c[i]!=c[i-1]){
            flag=1;
        }
    }
    if(flag==0){
        cout<<0;
        return 0;
    }
    int r=n,sum=0,num;
    int rc=c[r],ra=a[r];
    if(n%2==0){
        num=n/2;
    }
    if(n%2==1){
        num=n/2+1;
    }
    for(int i=1;i<=num;i++){
        if(rc==c[i]){
            if(ra==a[i]){
                --r;
                ra=a[r];
                rc=c[r];
                continue;
            }
            int ans=abs(ra-a[i]);
            ra=ans;
            if(a[i]>ra){
                --r;
                --i;
            }
            continue;
        }
        if(rc!=c[i]){
            if(ra==a[i]){
                sum+=a[i];
                --r;
                ra=a[r];
                rc=c[r];
                continue;
            }
            sum+=min(ra,a[i]);
            int ans=abs(ra-a[i]);
            ra=ans;
            if(a[i]>ra){
                rc=c[i];
                --r;
                --i;
            }
            else{
                rc=c[r];
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
