#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],sum[500005],ans[500005],cnt[500005];
ll f;
//struct p{
 //   int cnt,q;
//}
ll ch[500005];
/*bool cmp(p x,p y){
    return x.q<y.q;
}*/
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        //cout<<a[i]<<' ';
     //   if(a[i]==a[i-1]){
     //       ch[i].cnt=a[i];
     //   }
        ch[i]=a[i]-a[i-1];
        if(ch[i]!=ch[i-1]&&i!=2){
            f=-1;
        }
   //     cout<<ch[i]<<' ';
    }
    if(f==0){
        f=ch[2];
    }
    //sort(ch+1,ch+n+1);
    /*for(int i=2;i<=n;i++){
        ll t=0;
        if(ch[i].cnt>0){
            t=ch[i].cnt;
        }
        sum[i]+=ch[i]+ch[i-1];
        ans[i]+=sum[i]+ans[i-1];
     //   if(ch[i]==0)    sum[i]+=
    //    ch[i]=sum[i]+sum[i-1];
    }*/
    ll mx=-100;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ll t=0;
            if(f!=-1){
                t=(j-i+1)*(j-i)/2*f;
            }else{
                for(int k=i;k<j;k++){
                    t+=a[j]-a[k];
                    if(t>m) break;
                }
            }
            if(t<=m){
                if(mx<j-i+1){
                    mx=j-i+1;
                }
            }
        }
    }
    cout<<mx;
   /* for(int i=1;i<=n;i++){
        cout<<sum[i]<<' '<<ch[i]<<' '<<ans[i]<<endl;
    }
    int k=upper_bound(ans+1,ans+1+n,m)-ans-1;
    cout<<n-k;*/
	return 0;
}
