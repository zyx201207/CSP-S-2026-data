#include <bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	srand(time(NULL));
	for(int i=0;i<t;i++)
		cout<<rand()%5+1;
	return 0;
}
