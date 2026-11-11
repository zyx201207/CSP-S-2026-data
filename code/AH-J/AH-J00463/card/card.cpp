#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[500005];
stack<int>s;
bool have[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int t=1;t<=n;t++){
		for(int i=t;i<=n;i++)
		{
			if(have[a[i]]==false){s.push(a[i]);have[a[i]]=true;
			}
			else {
				while(s.top()!=a[i]){have[s.top()]=false;s.pop();
				}
			}
		}
		for(int i=1;i<=m;i++)if(have[i])sum[i]++;
		while(!s.empty())s.pop();
		memset(have,false,sizeof(have));
	} 
	for(int i=1;i<=m;i++)
	cout<<sum[i]<<' ';
	return 0;
}
