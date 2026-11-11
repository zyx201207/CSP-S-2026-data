#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x,maxx=-1;
	cin>>n>>m;
	for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x>maxx)maxx=x;
    }
	cout<<n<<m<<maxx;
	return 0;
}
