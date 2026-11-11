#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans[N],b[N],cnt=1,sum;
map<int,int> mp;
map<int,bool> fi;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
		fi[a[i]]=true;
	}
	for(int i=1;i<=n;i++)
	{
		if(fi[a[i]]==true)
		{
			ans[a[i]]=n-sum;
			sum+=mp[a[i]];
			cout<<ans[a[i]]<<' ';
			fi[a[i]]=false;
		}
	}
	return 0;
}
