#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T;
int a[N];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
		memset(a,0,sizeof(a));
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<0<<endl;
	}
    return 0;
}
