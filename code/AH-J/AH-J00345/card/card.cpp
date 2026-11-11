#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=3e5+10;
int n,m,a[N],ans[M];
unordered_map<int,int> mpf,mpl;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mpl[a[i]]=i;
		if(!mpf[a[i]]) mpf[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int lst=-1,ar;
		for(auto u:mpl) 
			if(u.second>lst)
			{
				ar=u.first;
				lst=u.second;
			}
		int fir=mpf[ar];
		if(fir<i)
		{
			map<int,bool> mp3;
			for(int j=i;j<=n;j++) mp3[a[i]]=1;
			for(auto u:mp3) ans[u.first]++;
		}
		else
		{
			map<int,bool> mp3;
			for(int j=i;j<=fir;j++) mp3[a[i]]=1;
			for(int j=lst;j<=n;j++) mp3[a[i]]=1;
			for(auto u:mp3) ans[u.first]++;
		}
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
