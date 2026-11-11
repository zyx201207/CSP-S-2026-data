#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int t1[N];
bool bo[N];
long long ans[N];
int js;
struct node{
	int x[25][3];
	long long hc[25];
	int cnt;
	int lin[25];
};
node s[N];
void dfs(int no,int en,int ti,int li)
{
	if(no==en)
	{
		js++;
		if(ans[js]==0)
		{
			ans[js]=ti+t1[en]+s[en].hc[li];
		}
		ans[js]=min(ti+t1[en]+s[en].hc[li],ans[js]);
		return;
	}
	int i,j;
	for(i=1;i<=s[no].cnt;i++)
	{
		for(j=1;j<=2;j++)
		{
			if(bo[s[no].x[s[no].lin[i]][j]]==false)
			{
				bo[s[no].x[s[no].lin[i]][j]]=true;
				if(li!=s[no].lin[i])
				{
					dfs(s[no].x[s[no].lin[i]][j],en,ti+s[no].hc[s[no].lin[i]]+s[no].hc[li],s[no].lin[i]);
				}
				else
				{
					dfs(s[no].x[li][j],en,ti,li);
				}
			}
		 } 
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>t1[i];
	}
	int t;
	int st,t2,la=0;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		cin>>st>>t2;
		s[st].hc[i]=t2;
		s[st].cnt++;
		s[st].lin[s[st].cnt]=i;
		for(int j=2;j<=t;j++)
		{
			la=st;
			cin>>st>>t2;
			s[la].x[i][2]=st;
			s[st].x[i][1]=la;
			s[st].hc[i]=t2;
			s[st].cnt++;
			s[st].lin[s[st].cnt]=i;
		}
	}
	int k,j;
	for(int i=1;i<=q;i++)
	{
		cin>>k>>j;
		bo[k]=true;
		dfs(k,j,t1[k],0);
		memset(bo,false,sizeof(bo));
		cout<<ans[js]<<'\n';
	}
	return 0;
} 


