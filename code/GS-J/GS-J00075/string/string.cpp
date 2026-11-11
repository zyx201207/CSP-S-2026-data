#include<bits/stdc++.h>
using namespace std;
long long int n,m,tmp;
struct wy{ 
	long long int s;
	char x;
}a[500100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		getchar();
		cin>>a[i].s>>a[i].x;
	}
	long long int l=1,r=n;
	for(int i=1;;i++)
	{
		if(l>r||l==r) break;
		if(a[l].x!=a[r].x)
		{
			if(a[l].s>a[r].s)
			{			
				a[l].s-=a[r].s;
				tmp+=a[r].s;
				r--;
			}
			else if(a[l].s<a[r].s)
			{			
				a[r].s-=a[l].s;
				tmp+=a[l].s;
				l++;
			}
			else
			{
				tmp+=a[r].s;
				l++,r--;				
			}
		}
		else
		{
			l++;
			r--;
		}
	}
	cout<<tmp;
	return 0;
}
