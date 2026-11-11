#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,ans,f1=1,f2=1;
int a[N],b[N],sum[N],sum1[N],ss1[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f1=0;
		}
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		if(b[i]!=b[i]-1&&i!=2){
			f2=0;
		}
		sum[i]=sum[i-1]+b[i];
	}
	if(f1){
		m*=2;
		for(int i=1;i<=n;i++){
			if(i*(i+1)>m){
				break;
			}
			ans=max(ans,i);
		}
		cout<<ans<<"\n";
		return 0;
	}
	else if(f2){
		m*=2;
		for(int i=1;i<=n;i++){
			if((a[1]+a[i])*a[i]>m){
				break;
			}
			ans=max(ans,i);
		}
		cout<<ans<<"\n";
		return 0;
	}
	for(int i=n;i>=1;i--){
		int s=0,ii=i,ci=0;
		while(s<=m){
			if(ii<1){
				break;
			}
			if(ci>=n){
				break;
			}
			s+=a[i]-a[ii];
			if(s>m){
				break;
			}
			ii--;
			ci++;
		}
		ans=max(ci,ans);
	}
	cout<<ans<<"\n";
	return 0;
}
/*5 5
1 2 4 8 9*/
/*5 8
-3 -1 2 2 7*/
//优先合成最近的 
//每个数字往自己左边算 
