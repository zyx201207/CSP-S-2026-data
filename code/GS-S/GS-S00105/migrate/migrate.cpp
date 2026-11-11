#include<bits/stdc++.h>
using namespace std;
const long long N=2e8;
long long c,t;
long long n,d;
long long x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<=t;i++){
		cin>>n>>d;
		for(int j=0;j<=n;j++){
			cin>>x[j];
		}
		if(n%2==0||d%2==0) cout<<1<<endl;
	}
	return 0;
}
