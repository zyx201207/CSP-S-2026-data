#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
string e;
long long sum=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		e[i-1]=c[i];
	}
	int top=1,tot=n,x=a[top],y=a[tot];
	for(int i=0;i<n/2;i++)
	{
		if(e[i]!=e[n-i-1])
		sum+=max(x,y);
		x=a[++top];
		y=a[--tot];
	}
	cout<<sum;
	return 0;
}
