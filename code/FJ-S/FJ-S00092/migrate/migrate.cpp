#include <bits/stdc++.h>
using namespace std;

int c,t;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>c>>t;
	
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		vector<long long> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cha=a[2]-a[1];
		if(cha>d){
			continue;
		}
		cout<<n/d-1<<endl;
		
	}

	return 0;
}

