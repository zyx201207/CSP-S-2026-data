#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=4010;
int c,t,n,k;
int mp[N][N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1,x,y;i<n;i++)
			cin>>x>>y;
		cout<<(n-1)/k-1<<"\n";
	}
}
