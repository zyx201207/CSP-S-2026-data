#include<bits/stdc++.h>
using namespace std;
const int M=2e6+5;
typedef long long ll;
ll a[M];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int k=1;k<=t;k++)
	{
		int n,d;
		cin>>n>>d;
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		if(sum==(a[1]+a[n])*n/2&&(a[2]-a[1])*2<=d) cout<<n-4+1<<'\n';
		else cout<<0<<'\n';
		memset(a,0,sizeof(a));
	} 
	return 0;
}
/*
0 2
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63
*/
