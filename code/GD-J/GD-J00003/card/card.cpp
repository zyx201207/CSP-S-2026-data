#include <bits/stdc++.h>
using namespace std;

int a[1000001];
int b[1000001]={1};

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	set<int> s;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s.insert(a[i]);
	}
	cout<<n<<" "<<m<<" "<<m;
}
