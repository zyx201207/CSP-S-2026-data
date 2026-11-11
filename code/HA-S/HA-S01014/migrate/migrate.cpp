#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,d,s=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			s+=x;
		}
		cout<<rand()%n<<endl;
	}
	return 0;
}
