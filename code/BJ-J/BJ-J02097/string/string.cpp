#include<bits/stdc++.h>
using namespace std;

int n,a[200015];
long long sum,ans;
char b[200015];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%s",&a[i],&b[i]);
        sum+=b[i];
    }
    long long t=0;//check the t
    int l=0,r=n-1;//l r num
    int ll=a[0],rr=a[n-1];
    while(l<=n){
        if(b[l]==b[r]){//same
            if(ll>rr){
                ll-=rr;
                r--;rr=a[r];
            }else if(ll<rr){
                rr-=ll;
                l++;
                ll=a[l];
            }else {
                l++;r--;
                ll=a[l];
                rr=a[r];
            }
        }else{
            if(ll>rr){
                ans+=rr;
                ll-=rr;
                r--;rr=a[r];
            }else if(ll<rr){
                ans+=ll;
                rr-=ll;
                l++;
                ll=a[l];
            }else{
                ans+=ll;
                l++;r--;
                ll=a[l];
                rr=a[r];
            }
        }
    }
    printf("%lld\n",(ans+1)/2);
    return 0;
}