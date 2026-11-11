#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long x[2*N+5],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int ans;
	int c,t;
	cin>>c>>t;
	int n;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		ans=0;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int j=d+d;j<=n;j++){
			ans++;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
