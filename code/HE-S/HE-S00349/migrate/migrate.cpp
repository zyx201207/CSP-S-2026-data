#include<bits/stdc++.h>
using namespace std;
int a,b,n,d,x[2000006];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a>>b;
	for(int i=0;i<b;++i)
    {
        cin>>n>>d;
        for(int i=0;i<n;++i) cin>>x[a];
        if(a>3&&(d>(x[2]-x[0]))&&(d<(x[3]-x[0]))) cout<<n-3<<endl;
        else cout<<0<<endl;
    }
	return 0;
}
