#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],ans[100005],b[100005];
stack<int> op;
map<int,int> mp,kp,lp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans[a[i]]=n;
	}
	for(int i=1;i<=n;i++)
	{
		int k=0;
		if(lp[a[i]])ans[a[i]]--;
		if(op.size()&&mp[a[i]])
		{
			while(op.top()!=a[i])
			{
				lp[op.top()]=1;
				op.pop();
				
			}
			lp[op.top()]=1;
			op.pop();
		}
		else if(!mp[a[i]])
		{
			op.push(a[i]);
			mp[a[i]]++;
		}
		
		while(op.size())
		{
			int x=op.top();op.pop();
			k++;
			b[k]=x;
		}
		for(int j=k;j>=1;j--)
		{
			op.push(b[j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!kp[a[i]])
		{
			kp[a[i]]=1;
			cout<<ans[a[i]]<<' ';
		}
	}
	return 0;
}
