#include <bits/stdc++.h>
using namespace std;

long long c,t,n;
int main()
{
	srand((long long)time(0));
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(long long a=1;a<=t;a++)
	{
		cin>>n;
		cout<<(rand()%n)+1<<endl;
	}
	return 0;
}
