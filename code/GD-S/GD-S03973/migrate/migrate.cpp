#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int T,n,m,c;
long long a[N];
void slv()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m>=(a[2]-a[1])*2 && m<(a[2]-a[1])*3)
		cout<<n-3<<endl;
	else cout<<0<<endl;
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	for(int i=1;i<=T;i++)
		slv();
	return 0;
} 
