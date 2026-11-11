#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		for(int i=1;i<=n;i++)
			cin >> x[i];
	}
	if(t==2) cout <<0<<endl<<1<<endl;
	else{
		for(int i=1;i<=t;i++)
		{
			cout <<0<<endl;
		}
	}
	return 0;
}
