#include<bits/stdc++.h>
using namespace std;
int main(){	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	vector<vector<long long> > v(T+2);
	vector<vector<long long> > k(T+2);
	cin>>c>>T;
	while(T--){
		int n;
		long long d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			long long a;cin>>a;
			v[T].push_back(a);
		}
		int k=v[T][1]-v[T][0];
		k=d/k;
		int w[n+9];
		for(int i=1;i<=n;i++){
			w[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				w[i+j]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(w[i]==2){
				ans++;
			}
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
