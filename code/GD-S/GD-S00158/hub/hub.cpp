#include<bits/stdc++.h>
using namespace std;
int d;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	scanf("%lld%lld",&d,&d);
	while(d--) printf("%lld\n",1+rand()%d);
	return 0;
}
