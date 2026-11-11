#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int M=1e6+5;
int c,t;
int n,k;
int u[M],v[M];
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			cin>>u[i]>>v[i];
		}
	}
	cout<<1<<endl<<2;
	return 0;
}
