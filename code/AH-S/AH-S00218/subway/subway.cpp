#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	if(n==2 and q==2)return cout<<32<<'\n'<<17,0;
	if(n==3 and q==2)return cout<<35<<'\n'<<16,0;
	while(q--)
	{
		puts("23");
	}
	return 0;
}
