#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,m,a,b;
	cin>>n>>m;
	cin>>b>>a;
	srand(time(0));
	for(int i=0;i<m;i++)
	{
		cout<<rand()%(b/a+2);
	}
	return 0;
}
