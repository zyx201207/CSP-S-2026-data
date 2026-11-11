#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m;
	n=n&m;
	m=n^7;
	n+=20;
	m+=10;
	cout<<n<<endl<<m;
	return 0;
}
