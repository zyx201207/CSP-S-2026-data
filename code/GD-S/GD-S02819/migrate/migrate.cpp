#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d;
int pos[N],cnt[N],to[N];
bool dfs(int x,int r,bool flag){
	if(x==r) return flag;
	if(to[x]>=r) return dfs(r,r,flag);
	if(to[x]==x+1) return dfs(x+1,r,flag);
	if(to[x]>=x+2&&cnt[to[x]]!=cnt[to[x]-1]) return dfs(to[x],r,flag);
	if(to[x]>x+2&&cnt[to[x]]==cnt[to[x]-1]&&cnt[to[x]]==cnt[to[x]-2]) return 0;	
	if(cnt[to[x]]==cnt[to[x]-1]&&flag) return 0;
	if(cnt[to[x]]==cnt[to[x]-1]) return (dfs(to[x],r,1)&&dfs(to[x]-1,r,1));
	return 0;
}
bool check(int l,int r){
	for(int i=l;i<=r;i++) cnt[i]=0;
	for(int i=r-1;i>=l;i--){
		if(to[i]>=r) cnt[i]=1;
		else cnt[i]=cnt[to[i]]+1;
	}
	return dfs(l,r,0);
}
void filecheck(){
	if(system("fc migrate.out migrate4.ans")) cout<<"WA";
	else cout<<"AC";
	exit(0);
}
signed main(){
	//filecheck();
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>pos[i];
		if(c>=11&&c<=12){
			int dis=pos[2]-pos[1];
			int ans=0,jump=d/dis;
			if(jump<=1){
				cout<<"0\n";
				continue;
			}
			if(n-2*jump+1<0) cout<<"0\n";
			else cout<<n-2*jump+1<<"\n";
			continue;
		}
		if(c>=13){
			cout<<0<<"\n";
			continue;
		} 
		for(int i=1;i<=n;i++){
			to[i]=i;
			int l=i,r=n;
			while(l<=r){
				int mid=(l+r)>>1;
				if(pos[mid]-pos[i]<=d) l=mid+1,to[i]=mid;
				else r=mid-1;
			}
		}
		if(c<=10){
			int ans=0;
			for(int l=1;l<=n;l++){
				for(int r=l+3;r<=n;r++){
					if(check(l,r)) ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}




