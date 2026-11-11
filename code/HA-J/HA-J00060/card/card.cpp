#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,a[500010],ans[500010],wan[500010],cnt=1,vis[500010],em[500010];
struct node{
	int l,r;
}nu[500100];
bool cmp(node x,node y){
	if(x.l==y.l){
		return x.r<y.r;
	}else{
		return x.l<y.l;
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(a[i]==a[j]){
				nu[cnt].l=j;
				nu[cnt].r=i;
				cnt++;
				break;
			}
		}
	}
	sort(nu+1,nu+cnt,cmp);
	for(int i=1;i<=n;i++){
		
		if(wan[i]==0){
			for(int j=1;j<=cnt;j++){
				if(nu[j].l>=i){
					wan[i]=j;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(wan[i]==0){
			wan[i]=cnt;
		}
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(em,0,sizeof(em));
		for(int j=1;j<cnt;j++){
			if(nu[j].l>=i){
				for(int k=nu[j].l;k<nu[j].r;k++){
					vis[k]=1;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(vis[j]==0){
				em[a[j]]=1;
			}
		}	
		for(int j=1;j<=m;j++){
			if(em[j]==1){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
