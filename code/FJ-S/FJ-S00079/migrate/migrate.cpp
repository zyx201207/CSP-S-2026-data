#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],s[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		memset(s,0,sizeof(s));
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		s[1]=1;
		for(int i=1;i<=n;i++){
			int k=i+1;
			for(int j=i+1;a[i]+d>=a[j]&&j<=n;j++){
				k=j;
			}
			s[k]+=s[i];
		}
		int ans=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				if(s[i]==s[j]*2){
					ans++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			cout<<s[i]<<' ';
		}
		cout<<ans<<'\n';
	}
	return 0;
}