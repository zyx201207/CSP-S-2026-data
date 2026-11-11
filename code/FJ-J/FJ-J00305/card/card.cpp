#include<iostream>
#include<stack>
using namespace std;
const int N=5*1e5+10;
int a[N],cnt[N]={0};
stack<int> b,c;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)//¾ÖÊý 
	{
		for(int j=i;j<=n;j++)//´òÅÆ 
		{
			int f=0;
			while(b.empty()==0)//±éÀúÅÆ 
			{
				if(a[j]==b.top())//ÅÐ¶ÏÔÚÄÄÄÃÅÆ 
				{
					b.pop();
					b.push(a[j]);
					f=1;
					break; 
				}
				c.push(b.top());
				b.pop();
			}
			if(f==0)
			{
				while(c.empty()==0)
				{
					b.push(c.top());
					c.pop();
				}
				b.push(a[j]);
			}else{
				while(c.empty()==0)
				{
					c.pop();
				}
			}
		}
		while(b.empty()==0)
		{
			cnt[b.top()]++;
			b.pop();
		}	
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
