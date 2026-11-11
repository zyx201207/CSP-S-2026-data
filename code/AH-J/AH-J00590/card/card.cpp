#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y;
int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>y;
    for(int i=2;i<=n;i++)
    {
		cin>>x;
		if(y>x)cout<<n-1;
	}
    return 0;
}
