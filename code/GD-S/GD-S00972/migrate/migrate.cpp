#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[1000050];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		int dis=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[1]>d&&a[i]-a[1]<2*d){
				dis=i;
			}
		}
		cout<<n-dis+1<<endl;
	}
	return 0;
}
