#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
char a[MAXN];
long long ans=0;
bool b=true;
int n,c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;	
	char a[MAXN];
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		ans+=x;
		string y;
		cin>>y;
		a[i]=y[0];
		a[0]=a[1];
		if(a[i]!=a[i-1])
		{
			b=false;	
		}
	}
	if(b==true)
	{
		cout<<'0';
		return 0;
	}
	ans=ans/2;
	cout<<ans;
	return 0;
}
