#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll b[N];
struct node{
	int to,nxt,l;
}a[N];
int k,pre[N],c[N];
void add(int u,int v,int d){
	a[++k]={v,pre[u],d};
	pre[u]=k;
}
ll bj,mi=LLONG_MAX;
void dfs(int x,int y,ll k){
	//cout<<x<<" "<<k<<"->\n";
	if(x>y){
	//	cout<<"!!!!!\n";
		return;
	}
	if(k>mi) return;
	c[x]=1;
	if(x==y){
		//cout<<"到达:"<<k<<"\n";
		if(k<mi) mi=k,bj=1;
		else if(k==mi) bj++;
		return;
	}
	for(int i=pre[x];i!=0;i=a[i].nxt){
		//if(x==2) cout<<a[i].to<<":";
		if(!c[a[i].to]){
			dfs(a[i].to,y,k+1);
			//cout<<"回溯至"<<x<<"\n";
			c[a[i].to]=0;	
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int g,T;
	cin>>g>>T;
	while(T--){
		memset(a,0,sizeof a);
		k=0;
		memset(pre,0,sizeof pre);
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>b[i];
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) if(abs(b[i]-b[j])<=d) add(i,j,abs(b[i]-b[j]));
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				bj=0,mi=LLONG_MAX;
				dfs(i,j,0);
				c[i]=0;
				//cout<<i<<"->"<<j<<" "<<bj<<"\n";
				if(bj==2) sum++;
				//cout<<"\n"<<i<<"->"<<j<<"-----------\n";
			}
		}
		cout<<sum<<"\n";
		//for(int i=pre[1];i!=0;i=a[i].nxt) cout<<a[i].to<<":";
	}
	return 0;
}

