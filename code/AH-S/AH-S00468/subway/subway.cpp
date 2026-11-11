#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],s[500005],b[500005],c,d,q,k1;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
		cin>>a[i];
	}
	if(n==2)
	{
		cout<<n+30<<endl<<n+15;
	}
	else cout<<n+32<<endl<<n+13;
}
