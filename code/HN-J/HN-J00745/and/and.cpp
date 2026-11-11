#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int a[N];
vector<int> cnt[32];
map<int,int> mp;
ll ans;
int top=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	int n,m;
	int x,tot=0,maxid=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[i]=x;
		tot=0;
		while(x>0){
			if(x&1) cnt[tot].push_back(i);
			x>>=1;
			tot++;
		}
		maxid=max(maxid,tot);
	}
	int id=0;
	for(int i=maxid;i>=0;i--)
	{
		if(cnt[i].size()>=m)
		{
			for(int x:cnt[i]) mp[x]=1;
			ans=ans+(pow(2,i));
			id=i;
			break;
		}
	}
	if(id==0) ans=1;
	
	for(int i=id-1;i>=0;i--)
	{
		if(cnt[i].size()<m) continue;
		
		int tot1=0;
		vector<int> tmp;
		for(int x:cnt[i])
		{
			if(mp[x]==top)
			{
				tot1++;
			    tmp.push_back(x);
			}
		}
		top++;
		for(int x:tmp) mp[x]=top;
		
		if(tot1>m) ans=ans+(pow(2,i));
		else if(tot1<m)
		{
			for(int x:cnt[id]) mp[x]=1;
		}
		else
		{
			ll anss=(pow(2,tot+1))-1;
			for(int x:cnt[i])
			{
				if(mp[x]==top) anss&=a[x];
			}
			cout<<anss;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
