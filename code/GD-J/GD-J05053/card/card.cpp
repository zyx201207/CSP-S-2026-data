#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e6+5;
int n,m,a[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	freopen("str.in","r",stdin);
//	freopen("dog.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
	{
		int bl[N]={};
		stack<int>ss;
		ss.push(0);
		for(int j=i;j<n;j++) 
		{
			if(bl[a[j]]==0)
			{
				bl[a[j]]=1;
				ss.push(a[j]);
			}
			else 
			{
				while(ss.top()!=a[j])
				{
					bl[ss.top()]=0;
					ss.pop();
				}
			}
		}
		while(!ss.empty())ans[ss.top()]++,ss.pop();
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
} 
