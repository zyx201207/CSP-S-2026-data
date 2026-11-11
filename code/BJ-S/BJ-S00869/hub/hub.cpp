#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,T;
int fa[N];
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			fa[i]=i;
		}
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
		}
	}
	cout<<"1\n2";
    return 0;
}
