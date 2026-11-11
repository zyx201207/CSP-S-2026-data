#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int c,t,n,k,len,st[MAXN][22],mindep,b[22],rdep,ans,dep[MAXN],flag[MAXN],flg[MAXN];
vector<int>lb[MAXN];
struct l{
	int dep,dat;
}leaf[MAXN];
void dfs(int now,int fa){
	st[now][0]=fa;
	dep[now]=dep[fa]+1;
	if(lb[now].size()==1&&lb[now][0]==fa){
		leaf[++len].dep=dep[now];
		leaf[len].dat=now;
		return ;
	}
	for(int i=0;i<lb[now].size();i++){
		int v=lb[now][i];
		if(v==fa){
			continue;
		}
		dfs(v,now);
	}
	return ;
}
void res(){
	for(int i=1;i<=20;i++){
		for(int j=1;j<=n;j++){
			st[j][i]=st[st[j][i-1]][i-1];
		}
	}
}
bool cmp(l a,l b){
	return a.dep>b.dep;
}
int up(int now,int dep){
	for(int i=20;i>=0;i--){
		if(dep>=b[i]){
			dep-=b[i];
			now=st[now][i];
		}
	}
	return now;
}
void dfs2(int now,int fa){
//	cout<<"del"<<now<<endl;
	flag[now]=0;
	flg[now]=1;
	for(int i=0;i<lb[now].size();i++){
		int v=lb[now][i];
		if(v==fa){
			continue;
		}
		dfs2(v,now);
	}
	return ;
}
void del(int now,int mid){
	int rnow=now;
	for(int i=1;i<=mid+1;i++){
		flag[now]=0;
		flg[now]=1;
	//	cout<<now<<" "<<mid<<endl;
		now=st[now][0];
	}
	int tr=up(rnow,mid);
	dfs2(tr,st[tr][0]);
}
void cal(int now){
	if(now==0){
		return ;
	}
	if(flg[now]){
		return ;
	}
	flg[now]=1;
	ans++;
	cal(st[now][0]);
}
bool chk(int mid){
	for(int i=1;i<=n;i++){
		flag[i]=0;
		flg[i]=0;
	}
	mindep=mid+1;
	for(int i=1;i<=len;i++){
		if(leaf[i].dep<=mid){
			mindep=min(mid-leaf[i].dep+1,mindep);
			break;
		}
		else{
			flag[up(leaf[i].dat,mid)]=1;
		}
	}
	if(leaf[1].dep<=mid){
		return 1;
	}
	if(leaf[2].dep<=mid){
		return leaf[1].dep-mid*3-mindep+2<=k;
	}
	rdep=leaf[2].dep-mid;
	del(leaf[1].dat,mid);
	del(leaf[2].dat,mid);
	int lnow=leaf[2].dat;
	for(int i=1;i<=leaf[2].dep;i++){
		flg[lnow]=1;
		lnow=st[lnow][0];
	}
	ans=rdep+1;
	flag[up(leaf[1].dat,mid*2+1)]=1;
	for(int i=1;i<=n;i++){
		if(flag[i]){
			cal(i);
		}
	}
	return ans<=k;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	b[0]=1;
	for(int i=1;i<=20;i++){
		b[i]=b[i-1]*2;
	}
	while(t--){
		cin>>n>>k;
		len=0;
		for(int i=1;i<=n;i++){
			lb[i].clear();
		}
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			lb[a].push_back(b);
			lb[b].push_back(a);
		}
		dfs(1,0);
		res();
		sort(leaf+1,leaf+n+1,cmp);
		int l=0,r=leaf[1].dep*2,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(chk(mid)){
				ans=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

