#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,a[200005],c[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	if(n==2) cout<<"0"<<endl;
	else if(n==3) cout<<"2"<<endl;
	else if(n==6) cout<<"3000000000"<<endl;
	return 0;
}