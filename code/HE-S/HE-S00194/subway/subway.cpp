#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=510;
int c,n,m,d,q;
int w[N];
struct node{
	int k;
	int a[M],t[M];
}s[M];
int vis[M][22];
int line=-1,head,tail;
bool flag[M];
long long endcount=INT_MAX,cnt,ans;
void dfs(int pos){
	if(pos==tail){
		cnt+=s[line].t[pos];
		endcount=min(cnt,endcount);
		return ;
	}
	for(int i=1;i<=vis[pos][0];i++){
		if(vis[pos][i]!=line){
			line=vis[pos][i];
			cnt+=s[line].t[pos];
		}
		for(int j=pos+1;j<=s[line].k;j++){
			if(j!=tail&&vis[j][0]==1) continue;
			if(flag[j]) continue;
			dfs(j);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(vis,0,sizeof(vis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>s[i].k;
		for(int j=1;j<=s[i].k;j++){
			cin>>s[i].a[j]>>s[i].t[j];
			if(vis[s[i].a[j]][0]==0){
				vis[s[i].a[j]][0]=1;
				vis[s[i].a[j]][1]=i;
			}else{
				vis[s[i].a[j]][0]++;
				vis[s[i].a[j]][vis[s[i].a[j]][0]]=i;
			}
		}
	}
	while(q--){
		cnt=0,ans=0,endcount=INT_MAX,line=-1;
		memset(flag,0,sizeof(flag));
		cin>>head>>tail;
		ans=ans+w[head]+w[tail];
		dfs(head);
		ans+=endcount;
		cout<<ans<<"\n";
	}
//	for(int i=1;i<=n;i++){
//		cout<<"#";
//		for(int j=0;j<s[i].p;j++){
//			cout<<s[i].change[j]<<" ";
//		}
//		cout<<"\n";
//	}
//	
	
	return 0;
}
