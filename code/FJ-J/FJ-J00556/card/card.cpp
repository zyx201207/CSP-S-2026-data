#include<bits/stdc++.h>
using namespace std;
priority_queue<pair< int,int> > q;
int n,m,a[500005],sum[300005],maxx[500005],ans,p[300005],s[300005];
vector<int> d[300005],f[300005];
int find(int x,int id)
{
	int l=0,r=d[id].size()-1,anss=0;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(d[id][mid]<=x)
		{
			l=mid+1;
			anss=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	return anss;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[a[i]]++;
		d[a[i]].push_back(i);
	}
	

	for(int i=1;i<=n;i++)
	{
		sum[a[i]]--;
		s[a[i]]=i;
		while(!q.empty()&&(sum[a[q.top().second]]==0||q.top().second!=s[a[q.top().second]]))
		{
			q.pop();	
		}
		if(!q.empty())
		{	
			maxx[i]=q.top().first+1;	
		}
		else
		{
			maxx[i]=1;
		}
		q.push({maxx[i],i});
	}
	for(int i=1;i<=m;i++)
	{
		f[i].push_back(d[i][0]-maxx[d[i][0]]+1);
		int o;
		for(int j=1;j<d[i].size();j++){
			if(maxx[d[i][j]]!=d[i][j]){
			
			o=find(maxx[d[i][j]],i);
		}
		else
		{
			o=find(maxx[d[i][j]]-1,i);
		}
		if(maxx[d[i][j]]<=d[i][0])
		{
			f[i].push_back(max(0,maxx[d[i][j]]-maxx[d[i][0]]+1)+d[i][j]-maxx[d[i][j]]+1);
			continue;
		}
			if(o+1<=d[i].size()){
			
			f[i].push_back(f[i][o]+max(0,maxx[d[i][j]]-maxx[d[i][o+1]]+1)+d[i][j]-maxx[d[i][j]]+1);
		}
		else
		{
						f[i].push_back(f[i][o]+d[i][j]-maxx[d[i][j]]+1);

		}
			
			}
			
		cout<<f[i][d[i].size()-1]<<" ";
		
	}
	
	return 0;
}
