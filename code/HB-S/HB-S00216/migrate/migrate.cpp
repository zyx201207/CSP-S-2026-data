#include<bits/stdc++.h>
using namespace std;
int n,m,a,c;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m>>a>>c;
	n=a^m;
	m=n&c;
	if(c>=2) n=1;
	if(a>=2) m=0;
	if(c<0) n=1;
	if(a<0) m=2;
	cout<<n-1<<endl<<m+1;
	return 0;
}
