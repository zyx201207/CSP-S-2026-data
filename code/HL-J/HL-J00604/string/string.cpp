#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum,L[200010],R[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L[i]=sum+1;
        sum+=a[i];
        R[i]=sum;
    }
    long long l=0,r=0,l2=0,r2=0,cnt=n,ans=0,mod=0;
    for(int i=1;i<=n;i++){
        l=L[i];
        r=R[i];
        r2=sum+1-l;
        l2=sum+1-r;
        long long x=0,y=0;
        if(l2>r+1){
            while(cnt>i){
                if(mod>0){
                    y=L[cnt]+mod-1;
                }
                else y=R[cnt];
                x=L[cnt];
                if(x>l2){
                    if(c[cnt]!=c[i]){
                        ans+=y-x+1;
                    }
                    cnt--;
                }else{
                    if(c[cnt]!=c[i])ans+=y-l2+1;
                    mod=l2-x;
                    if(mod==0)cnt--;
                    break;
                }
            }
        }else{
            while(cnt>i){
                if(c[cnt]!=c[i]){
                    if(mod>0){
                        ans+=mod;
                        mod=0;
                    }
                    else ans+=a[cnt];
                }
                cnt--;
            }
            break;
        }
    }
    cout<<ans;
    return 0;
}

