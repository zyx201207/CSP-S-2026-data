#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+5;
int c,T;
int a[maxn],n,k;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--)
    {
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			cin>>u>>v;
		}
		cout<<(n/k)-1<<"\n";
	}
    return 0;
}
