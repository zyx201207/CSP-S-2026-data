#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
//bf
int a[N],vis[N],n,m,maxa;
vector<int> slctnm;
void slct(int k)
{
	if(k==0)
	{
		int num=slctnm.front();
		for(int i=1;i<m;i++)
		{
			num&=slctnm.back();
			slctnm.pop_back();
		}
		maxa=max(maxa,num);
	}else{
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				vis[i]=1;
				slctnm.push_back(a[i]);
				slct(k-1);
				slctnm.pop_back();
				vis[i]=0;
			}
		}
	}
}
//\bf
int main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	slct(m);
	cout<<maxa;
	return 0;
}