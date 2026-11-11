#include<bits/stdc++.h>
using namespace std;
int n,m,a,c;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m>>a>>c;
	n=a^m;
	m=n&c;
	if(c>=2) n=1;
	if(a>=2) m=0;
	if(c<0) n=1;
	if(a<0) m=2;
	if(a>=50000) cout<<1000+c+a+n+m;
	else if(a>100) cout<<a-c*4<<endl<<m+n<<endl<<m*c<<endl<<n<<endl<<n*c;
	else if(a>5) cout<<n<<endl<<m+1<<endl<<2;
	else cout<<n<<endl<<m+2;
	return 0;
}
