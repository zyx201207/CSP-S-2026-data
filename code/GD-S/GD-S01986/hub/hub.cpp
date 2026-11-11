#include<iostream>
using namespace std;
int c,t,n,w;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<n;i++) cin>>w>>c;
		cout<<n/2;
	}
	fclose(stdin);
	fclose(stdout);
}
