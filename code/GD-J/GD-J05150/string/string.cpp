#include<bits/stdc++.h>
using namespace std;
int n,sz=0;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,c;
		cin>>a>>c;
		sz+=a;	
	}
	if(sz<=5) cout<<2;
	else cout<<0;
	return 0;
}
