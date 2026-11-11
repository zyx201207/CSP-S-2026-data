#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,i,l,j,t,w[1000001],aa,bb,ans,cnt,a[1000001],o,u,ww[10001][10001],anss;
long long s[1001][1001][3];
long long k[1001][1001]; 
void dfs(long long aaa,long long lu) {
	if(aaa==bb) {
		ans=min(ans,cnt+ww[aaa][lu]);
	}
	else {
		if(s[aaa][lu][1]!=aaa&&w[s[aaa][lu][1]]==0) {
			w[s[aaa][lu][1]]=1;
			dfs(s[aaa][lu][1],lu);
			w[s[aaa][lu][1]]=0;
		}
		if(s[aaa][lu][2]!=aaa&&w[s[aaa][lu][2]]==0) {
			w[s[aaa][lu][2]]=1;
			dfs(s[aaa][lu][2],lu);
			w[s[aaa][lu][2]]=0;
		}
		for(int j=1;j<=n;j++) {
			if(k[aaa][j]==1&&j!=lu&&w[s[aaa][lu][1]]==0) {
				cnt+=ww[aaa][j]+ww[aaa][lu];
				w[s[aaa][lu][1]]=1;
				dfs(s[aaa][j][1],j);
				w[s[aaa][lu][1]]=0;
				cnt-=ww[aaa][j]+ww[aaa][lu];
			}
			if(k[aaa][j]==1&&j!=lu&&w[s[aaa][lu][2]]==0) {
				cnt+=ww[aaa][j]+ww[aaa][lu];
				w[s[aaa][lu][2]]=1;
				dfs(s[aaa][j][2],j);
				w[s[aaa][lu][2]]=0;
				cnt-=ww[aaa][j]+ww[aaa][lu];
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++) cin>>a[i];
	for(i=1;i<=n;i++) {
		cin>>l;
		for(j=1;j<=l;j++) {
			cin>>t>>u;
			if(j!=1) {
				s[o][i][1]=t;
				s[t][i][2]=o;
			} 
			ww[t][i]=u;
			o=t;
			k[t][i]=1;
		}
	}
	for(i=1;i<=q;i++) {
		cin>>aa>>bb;
		ans=1e9,cnt=0,anss=1e9;
		for(j=1;j<=n;j++) {
			if(k[aa][j]==1) {
				if(s[aa][j][1]!=0){
					memset(w,0,sizeof(w));
					w[s[aa][j][1]]=1;
					dfs(s[aa][j][1],j);
				}
				anss=min(ans+a[aa]+a[bb]+ww[aa][j]+ww[bb][j],anss);
				if(s[aa][j][2]!=0) {
					memset(w,0,sizeof(w));
					w[s[aa][j][2]]=1;
					dfs(s[aa][j][2],j);
				}
				anss=min(ans+a[aa]+a[bb]+ww[aa][j],anss);
			}
		}
		cout<<anss<<endl;
	}
} 
