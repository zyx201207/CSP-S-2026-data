#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=3e5+5;
LL a[N],maxn,n,m;
void ds(LL cnt,LL an,LL ans){
	if(cnt>n&&ans<m) return;
	if(ans>m){
		maxn=max(maxn,an);
		return;
	}ds(cnt+1,an,ans);
	if(an==0) ds(cnt+1,a[cnt],ans+1);
	else ds(cnt+1,a[cnt]&an,ans+1);
}int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(n<=20){ds(1,0,1);cout<<maxn;}
	else{
        if(m==1){
            for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
            cout<<maxn;
        }else if(m==n){maxn=a[1];
            for(int i=1;i<=n;i++){
                maxn&=a[i];
            }cout<<maxn;
        }else if(m==2){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    maxn=max(maxn,a[i]&a[j]);
                }
            }cout<<maxn;
        }
	}
    return 0;
}
