#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
long long minn;
bool vis1[20001],vis2[501];
struct node1{
	int k,a[20001],t[20001];
}su[501];
struct node2{
	int w,cnt=0,sub[501];
}st[20001];
void dfs(int now,long long t,int s0){
	if(now==y){
		for(int i=1;i<=su[s0].k;i++){
			if(su[s0].a[i]==now){
				t+=su[s0].t[i];
				break;
			}
		}
		minn=min(minn,t);
		return;
	}
	for(int i=1;i<=st[now].cnt;i++){
		for(int j=1;j<=su[st[now].sub[i]].k;j++){
			if(vis1[su[st[now].sub[i]].a[j]]==0&&vis2[st[now].sub[i]]==0){
				vis1[su[st[now].sub[i]].a[j]]=1;
				vis2[st[now].sub[i]]=1;
				if(s0!=st[now].sub[i]){
					t+=su[s0].t[now];
					for(int l=1;l<=su[st[now].sub[i]].k;l++){
						if(su[st[now].sub[i]].a[l]==now){
							t+=su[st[now].sub[i]].t[l];
							break;
						}
					}
				}
				dfs(su[st[now].sub[i]].a[j],t,st[now].sub[i]);
				vis1[su[st[now].sub[i]].a[j]]=0;
				vis2[st[now].sub[i]]=0;
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>st[i].w;
	}
	for(int i=1;i<=n;i++){
		cin>>su[i].k;
		for(int j=1;j<=su[i].k;j++){
			cin>>su[i].a[j]>>su[i].t[j];
			st[su[i].a[j]].sub[++st[su[i].a[j]].cnt]=i;
		}
	}
	while(q--){
		cin>>x>>y;
		minn=0x3f3f3f3f;
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		vis1[x]=1;
		dfs(x,st[x].w+st[y].w,0);
		cout<<minn<<'\n';
	}
	return 0;
} 
