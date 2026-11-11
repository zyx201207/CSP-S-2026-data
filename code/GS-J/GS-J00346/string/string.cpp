#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
int n;cin>>n;
int a[10005];
char b[1005];
for(int i=0;i<n;i++)
{
	cin>>a[i];
	cin>>b[i];
}
if(n==1)
{
	cout<<"0";
	return 0;
}
bool x=true;
for(int i=0;i<n;i++)
{
	if(b[i]!=b[i+1])
	{
		x=false;
		break;
	}
}
if(x==0)
{
	cout<<"0";
}
}
