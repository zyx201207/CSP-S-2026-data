#include<bits/stdc++.h>
using namespace std;
struct nb{
	int num;
	char zm;
}wl[220000];
long long n,ans,top;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>wl[i].num;
		cin>>wl[i].zm;
	}
	top=n;
	int i=1;
	while(i<top)
	{
		char a=wl[i].zm;
		int aa=wl[i].num;
		while(aa>0)
		{
			if(wl[top].num>aa)
			{
				if(wl[top].zm!=a)
				ans+=aa;
				wl[top].num-=aa;
				aa=-1;
			}
			else
			{
				if(wl[top].zm!=a)
				ans+=wl[top].num;
				aa-=wl[top].num;
				top--;
			}
		}
		i++;
	}
	cout<<ans;
}