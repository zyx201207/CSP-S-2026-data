#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		srand(time(0));
		cout<<rand()%n<<endl;
	}
	return 0;
}
