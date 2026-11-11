#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],mx,ans,s,sum[35],an,aa,num,nn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}while(mx){
		mx>>=1;
		ans++;
	}s=(1<<ans)-(1<<(ans-1)),an=ans;
	while(s){
		for(int i=1;i<=n;i++){
			if(a[i]>=s){
				sum[ans]++;
				if(a[i]) nn++;
			}
		}
		if(sum[ans]>m){
			for(int i=1;i<=n;i++){
			if(a[i]>=s){
				a[i]-=s;
			}else a[i]=0;
		}
		}
		s>>=1,ans--;
	}int j=0;
	for(int i=1;i<=an;i++,j++) if(sum[i]>=m) num+=1<<j;
	printf("%lld",num);
}
