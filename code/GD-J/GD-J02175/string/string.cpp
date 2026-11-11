#include<iostream>
#include<cmath>
#define int long long
using namespace std;
const int N = 2e5;
struct node
{
	int num;
	char type;
}a[N+5];
int n;

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int num;char type;
		cin>>num>>type;
		
		a[i] = {num,type};
	}
	
	int l = 1;
	int r = n;
	int need = 0;
	while(l<r)
	{
		if(a[l].type==a[r].type)
		{
			int minn = min(a[l].num,a[r].num);
			a[l].num-=minn;a[r].num-=minn;
		}
		else
		{
			int minn = min(a[l].num,a[r].num);
			a[l].num-=minn;a[r].num-=minn;
			
			need+=minn;
		}
		
		if(a[l].num==0) l++;
		if(a[r].num==0) r--;
	}
	
	cout<<need;
	return 0;
}
