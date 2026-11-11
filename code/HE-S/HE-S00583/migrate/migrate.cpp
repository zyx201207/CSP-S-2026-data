#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e3+5;
ll c,n,d;
ll a[N],f1[N],f2[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			memset(f1,0,sizeof(f1));
			memset(f2,0,sizeof(f2));
			f2[i]=1;
			for(int j=i+1,k=i;j<=n;j++){
				while(a[j]-a[k]>d&&k<j){
					k++;
				}
				if(k==j)break;
				f1[j]=f1[k]+1;
				f2[j]+=f2[k];
				for(int l=k+1;l<j&&f1[k]==f1[l];l++){
					f2[j]+=f2[l];
					if(f2[j]>2){
						f2[j]=3;
						break;
					}
				}
				if(f2[j]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
