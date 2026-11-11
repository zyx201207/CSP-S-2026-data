#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;

struct node{
	int a[N];
	int x[N];
	int id;
}tcl;

int ans=0;
void two(int xxx)
{
	int xx=1;
	while(1)
	{
		if(xxx==1)
		{
			continue;
		}
		if(xxx/2>1 && xxx%2==0)
		{
			tcl.x[xx]=0;
			
		}else if(xxx/2==1 || xxx%2!=0)
		{
			tcl.x[xx]=1;
		}
		xx++;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>tcl.a[i];
		two(tcl.a[i]);
	}
	sort(tcl.a+1,tcl.a+n+1);
	sort(tcl.x+1,tcl.x+1+n);
	for(int i=1;i<=n;i++)
	{
		tcl.id=i;
	}
	for(int i=n;i<=n-m;i--)
	{
		
	}
	return 0;
}
