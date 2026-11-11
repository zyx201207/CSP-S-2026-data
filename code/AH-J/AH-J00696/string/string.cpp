#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
LL a[N],n,ans,tot;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(LL i=1;i<=n;i++){
        LL x;
        char y;
        scanf("%lld %c",&x,&y);
        if(i>1&&y==c[tot]) a[tot]+=x;
        else a[++tot]=x,c[tot]=y;
    }
    if(tot==1){
        cout<<0;
        return 0;
    }
    LL i=1,j=tot;
    while(i<j){
        LL k=a[i],sum=0;
        while(sum<k){
            if(sum+a[j]<=k){
                if(c[j]!=c[i]) ans+=a[j];
                sum+=a[j];
                j--;
            }else{
                if(c[j]!=c[i]) ans+=k-sum;
                a[j]=sum+a[j]-k;
                sum=k;
            }
        }
        i++;
    }
    cout<<ans;
    return 0;
}
