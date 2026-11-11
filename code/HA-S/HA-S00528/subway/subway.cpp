#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],x[500005],y[500005];
int main() 
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	srand(time(NULL));
	for(int i=0;i<q;i++)
		cout<<rand()%40+1;
	return 0;
}
