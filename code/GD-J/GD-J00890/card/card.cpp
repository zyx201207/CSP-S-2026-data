#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[500005],ans[300005];
bool v[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>5000)
	{
		if(m==1)
		{
			cout<<n;
			return 0;
		}
		if(a[n]==1)
		{
			int s=0;
			for(int i=1;i<=n;i++)
				if(a[i]==2)
					s++;
			cout<<n<<" "<<s;
		}
		else
		{
			int s=0;
			for(int i=1;i<=n;i++)
				if(a[i]==1)
					s++;
			cout<<s<<" "<<n;
		}
		return 0;
	}
	for(int k=1;k<=n;k++)
	{
		stack<int>s;
		for(int i=1;i<=n;i++) v[i]=0;
		for(int i=k;i<=n;i++)
		{
			if(v[a[i]])
				while(!s.empty())
				{
					x=s.top();
					s.pop(),v[x]=0;
					if(x==a[i]) break;
				}
			s.push(a[i]),v[a[i]]=1;
		}
		while(!s.empty()) ans[s.top()]++,s.pop();
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
