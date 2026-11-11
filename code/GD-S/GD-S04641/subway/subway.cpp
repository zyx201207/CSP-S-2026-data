#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
const int maxn =5e5+10;
int w[maxn];
int cnt[maxn];
struct node{
	int t,id;
}s[maxn][25];
vector<node> p[505]; 
void work1()
{
	long long ans=1e18;
	int id;
	for(int i=1;i<=m;i++)
	{
		if(cnt[i]==2)
		{
			if(s[i][1].t+s[i][2].t<ans) 
			{
				id=i; ans=s[i][1].t+s[i][2].t;
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
	//	cout<<cnt[x]<<" "<<cnt[y]<<" "<<ans<<" "<<s[x][1].t<<" "<<s[y][1].t<<endl;
		ll a=w[x]+w[y]+s[x][1].t+s[y][1].t;
		if(cnt[x]==1&&cnt[y]==1&&s[x][1].id==s[y][1].id)
		{
			cout<<a<<endl;
			continue;
		}
		else if(cnt[x]==1&&cnt[y]==1)
		{
			a+=ans;
			cout<<a<<endl;
			continue;
		}
		else if(cnt[x]==2&&cnt[y]==2)
		{
			 ll b=w[x]+w[y]+s[x][2].t+s[y][2].t;
			if(s[x][1].t+s[y][1].t<=s[x][2].t+s[y][2].t) 
			{
				cout<<a<<endl;
			}
			else{
				cout<<b<<endl;
			}
			continue;
		}
		else if(cnt[x]==1&&cnt[y]==2){
		
			if(s[x][1].id==s[y][1].id)
			{
				ll b=w[x]+w[y]+s[x][1].t+s[y][2].t+ans;
 	            ll a=w[x]+w[y]+s[x][1].t+s[y][1].t;
 	            if(a<=b) cout<<a<<endl;
 	            else cout<<b<<endl;
			}
			else{
				ll b=w[x]+w[y]+s[x][1].t+s[y][2].t;
 	            ll a=w[x]+w[y]+s[x][1].t+s[y][1].t+ans;
 	            if(b<=a+ans) cout<<b<<endl;
 	            else cout<<a+ans<<endl;
			}
		}
			else if(cnt[x]==2&&cnt[y]==1){
			if(s[x][1].id==s[y][1].id)
			{
				ll b=w[x]+w[y]+s[x][2].t+s[y][1].t+ans;
 	            ll a=w[x]+w[y]+s[x][1].t+s[y][1].t;
 	            if(a<=b) cout<<a<<endl;
 	            else cout<<b<<endl;
			}
			else{
				ll b=w[x]+w[y]+s[x][2].t+s[y][1].t;
 	            ll a=w[x]+w[y]+s[x][1].t+s[y][1].t+ans;
 	            if(b<=a) cout<<b<<endl;
 	            else cout<<a<<endl;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			scanf("%d%d",&a,&t);
			s[a][++cnt[a]].id=i;
			s[a][cnt[a]].t=t;
			node tmp; tmp.id=a,tmp.t=t;
			p[i].push_back(tmp);
		}
	}
    work1();
	return 0;
 } 
