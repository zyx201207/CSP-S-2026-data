#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n;
		cin>>n;
		srand(20261031);
		cout<<rand()%n<<'\n';
	}
	return 0;
}
