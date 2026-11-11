#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=0;
struct node
{
	int k;
	char c;
	int f;
};
struct stu
{
	int d;
	char s;
};
node a[200005];
stu A,B;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].k>>a[i].c;
		a[i].f=0;
	}
	int x=0,y=n+1;
	while(1)
	{
		if(A.d==0)
		{
			if(a[x+1].f==0)
			{
				x++;
				a[x].f=1;
				A.d=a[x].k;
				A.s=a[x].c;
			}else
			{
				break;
			}
		}if(B.d==0)
		{
			if(a[y-1].f==0)
			{	
				y--;
				a[y].f=1;
				B.d=a[y].k;
				B.s=a[y].c;
			}else
			{
				break;
			}
		}
		if(A.s==B.s)
		{
			A.d-=min(A.d,B.d);
			B.d-=min(A.d,B.d); 
		}else
		{
			sum+=min(A.d,B.d);
			A.d-=min(A.d,B.d);
			B.d-=min(A.d,B.d); 
		}
	}
	cout<<sum;
	return 0;
} 
