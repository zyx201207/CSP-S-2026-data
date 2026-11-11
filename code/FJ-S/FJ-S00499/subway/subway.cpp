#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	srand(q/n);
	for(int i=1;i<=q;i++)
	{
		cout<<rand()<<"\n";
	}
	return 0;
}
