#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pa pair<int,int>
#define mkp make_pair
#define FI first
#define SE second
int c,t,n,d,a[2000005],nxt[2000005],las[2000005],ans;
int qz[2000005],hz[2000005];
void check(int x){
	int y=nxt[x],z=nxt[y];
	if(nxt[y-1]==nxt[y-2]||y<=x+1)return ;
	if(nxt[x-1]==y-1)qz[x]=1; 
	if(nxt[y]!=nxt[y-1]){
		ans+=qz[x]*(nxt[y-1]-nxt[y-2]);
	}else ans+=qz[x]*(hz[z]+nxt[y]-nxt[y-2]-1);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			las[i]=nxt[i]=qz[i]=hz[i]=0;
		}
		for(int i=n,now=n;i>=1;i--){
			while(a[now]>a[i]+d){
				now--;
			}
			nxt[i]=now;
			las[now]=max(las[now],i);
		}
		for(int i=n;i>=1;i--){
			if(!las[i])las[i]=las[i+1];
		}
		las[1]=0;
		for(int i=1,now=0;i<=n;i++){
			if(las[i]==las[i-1]&&las[i]!=0)now++;
			else now=1;
			if(nxt[i]==nxt[i-1])qz[i]=1;
			else qz[i]++;
			qz[nxt[i]]+=qz[i];
		}
		for(int i=n;i>=1;i--){
			if(nxt[i]==nxt[i-1])hz[i]=1;
			else hz[i]=hz[nxt[i]]+nxt[i]-nxt[i-1];
		}
		for(int i=1;i<=n;i++)check(i);
		cout<<ans<<'\n';
	}
	return 0;
}

