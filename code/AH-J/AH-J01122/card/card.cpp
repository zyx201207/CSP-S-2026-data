#include<bits/stdc++.h>
using namespace std;
//a pai b zhuomian
queue<int>a,b;
const int N=3005;
int n,m,cnt[N],w[5005],flag[N],q=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		w[i]=x;
		a.push(x);
		if(w[i]!=w[i-1]&&i!=1)
		{
			q=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int s=w[j];
			a.pop();
			if(flag[s]==0)
			{
				b.push(s);
				flag[s]=1;
			}	
			else
			{
				while(!b.empty())
				{
					b.pop();
				}
				b.push(s);
			}
		}
		while(!b.empty())
		{
			cnt[b.front()]++;
			b.pop();
		}
		for(int j=i;j<=n;j++)
			a.push(w[j]);
		cout<<endl;
		memset(flag,0,sizeof flag);
	}
	for(auto x:cnt)
		if(x)
			cout<<x<<" ";
	return 0;
}

