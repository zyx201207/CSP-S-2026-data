#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int MN = -2e18;

int c,t;
int n,d;
int a[2000010],f[2000010],s[2000010];
map<int,int>m;

signed main( ){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int l=i,k=i;
			for(int j=1;j<=n;j++) f[j]=s[j]=0;
			s[i]=1;
			m.clear();
			m[f[i]]+=s[i];
			for(int j=i+1;j<=n;j++){
				while(a[j]>a[l]+d) l++;
				f[j]=f[l]+1;
				while(a[l]>a[k]){
					m[f[k]]-=s[k];
					k++;
				}
				s[j]=m[f[l]];
				if(s[j]==2){
//					cout<<i<<" "<<j<<endl;
					ans++;
				}
				m[f[j]]+=s[j];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
