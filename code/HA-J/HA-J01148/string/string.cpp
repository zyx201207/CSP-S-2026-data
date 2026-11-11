#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b[100005];
	cin>>a;
	char c[100005];
	for(int i=0;i<a;i++)
	{
		cin>>b[i]>>c[i];
	}
	if(a==1)cout<<0;
	if(a==2&&b[0]==b[1])cout<<(b[0]+b[1])/2;
	else cout<<((b[0]+b[1])/2)+1;
	return 0;
}
