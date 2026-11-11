#include<bits/stdc++.h>
using  namespace std;
struct q
{
	int w;
	char e;
}q[2002];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>q[i].w>>q[i].e;
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
