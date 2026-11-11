#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=6e5+10,M=550,NQ=1e5+10;
struct node{
	ll x,t;
	bool operator <(const node &no)const{
		return no.t<t;
	}
};
struct ques{
	ll x,y,ans,id;
}qs[NQ];
priority_queue<node> q;
vector<node> e[N];
ll m,n,d,Q,a[N],siz[M],dis[N];
bool vis[N];
bool cmp1(ques x,ques y){
	if(x.x==y.x)return x.y<y.y;
	return x.x<y.x;
}
bool cmp2(ques x,ques y){
	return x.id<y.id;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>m>>m>>n>>d>>Q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>siz[i];
		for(int j=1;j<=siz[i];j++){
			node pt;
			cin>>pt.x>>pt.t;
			e[n+i].push_back(pt);
			node nw=pt;
			nw.x=n+i;
			e[pt.x].push_back(nw);
		}
	}
	n+=m;
	for(int i=1;i<=Q;i++){
		int x,y;
		cin>>x>>y;
		if(x>y)swap(x,y);
		qs[i].x=x;qs[i].y=y;qs[i].id=i;
	}
	sort(qs+1,qs+1+Q,cmp1);
	for(int i=1;i<=Q;i++){
		int j=i;
		while(qs[j+1].x==qs[i].x&&j+1<=Q)j++;
		for(int k=1;k<=n;k++){
			dis[k]=1e18;
			vis[k]=false;
		}
		while(!q.empty())q.pop();
		q.push({qs[i].x,0});
		dis[qs[i].x]=0;
		while(!q.empty()){
			node tp=q.top();
			q.pop();
			vis[tp.x]=true;
			for(int k=0;k<e[tp.x].size();k++){
				node v=e[tp.x][k];
				if(dis[v.x]>dis[tp.x]+v.t){
					dis[v.x]=dis[tp.x]+v.t;
					if(!vis[v.x])q.push({v.x,dis[v.x]});
				}
			} 
		}
		while(i<=j){
			qs[i].ans=dis[qs[i].y]+a[qs[i].y]+a[qs[i].x];
			i++;
		}
		i=j;
	}
	sort(qs+1,qs+1+Q,cmp2);
	for(int i=1;i<=Q;i++)cout<<qs[i].ans<<"\n";
	return 0;
}

