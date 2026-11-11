#include<bits/stdc++.h>
#define int long long
#define endl putchar('\n')
#define psp putchar(' ')
using namespace std;
const int N=2e6+5;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10){
		putchar(x+'0');
		return;
	}
	print(x/10);
	putchar(x%10+'0');
}
int n,m,k;
int T;
int X[N];
int cnt[5005][5005];
int dis[5005];
int vis[5005];
vector<int>a[5005];
int d;
signed main(){
	//ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read();
	T=read();
	if(c<=10){
		while(T--){
			n=read(),d=read();
			for(int i=1;i<=n;i++)X[i]=read(),a[i].clear();
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					cnt[i][j]=0;
					if(abs(X[i]-X[j])<=d){
						a[i].push_back(j);
					}
				}
			}
			queue<int>q;
			for(int rt=1;rt<=n;rt++){
				for(int i=1;i<=n;i++)vis[i]=0,dis[i]=1e9;
				while(!q.empty())q.pop();
				q.push(rt);
				dis[rt]=0;
				vis[rt]=1;
				cnt[rt][rt]=1;
				while(!q.empty()){
					int x=q.front();
					q.pop();
					for(int i=0;i<a[x].size();i++){
						int y=a[x][i];
						if(vis[y]){
							if(dis[x]+1==dis[y])cnt[rt][y]+=cnt[rt][x];
						}
						else{
							dis[y]=dis[x]+1;
							cnt[rt][y]=cnt[rt][x];
							vis[y]=1;
							q.push(y);
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(cnt[i][j]==2)ans++;
				}
			}
			print(ans),endl;
		}
		return 0;
	}
	if(c==11||c==12){
		while(T--){
			n=read(),d=read();
			for(int i=1;i<=n;i++)X[i]=read();
			if(n==1||n==2||n==3){
				print(0),endl;
				continue;
			}
			int del=X[2]-X[1];
			if(del>d){
				print(0),endl;
				continue;
			}
			if(d/del==1||d>=X[n]-X[1]){
				print(0),endl;
				continue;
			}
			int mx=d/del;
			int ans=0;
			for(int i=1;i<=n;i++){
				if(i-(2*mx-1)>=1)ans++;
				if(i+(2*mx-1)<=n)ans++;
			}
			print(ans/2),endl;
		}
		return 0;
	}
	while(T--){
		n=read(),d=read();
		for(int i=1;i<=n;i++)X[i]=read();
		if(n==1||n==2||n==3||d>=X[n]-X[1]){
			print(0),endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int l=i,r=n;
			while(l<r){
				int mid=l+1+r>>1;
				if(X[mid]-X[i]<=d)l=mid;
				else r=mid-1;
			}
			int r1=r;
			l=r1,r=n;
			while(l<r){
				int mid=l+1+r>>1;
				if(X[mid]-X[r1]<=d)l=mid;
				else r=mid-1;
			}
			int r2=r;
			if(r1<=i+1||r2==r1)continue;
			if(X[r1+1]-X[r1-1]>d)continue;
			l=0,r=r2-r1-1;
			while(l<r){
				int mid=l+r>>1;
				if(X[r2-mid]-X[r1-1]<=d)r=mid;
				else l=mid+1;
			}
			int Ldel=l;
			if(X[r2-Ldel]-X[r1-1]>d)continue;
			l=0,r=r2-r1-1;
			while(l<r){
				int mid=l+1+r>>1;
				if(X[r2-mid]-X[r1-2]>d)l=mid;
				else r=mid-1;
			}
			int Rdel=l;
			if(X[r2-Rdel]-X[r1-2]<=d)continue;
			if(Ldel<=Rdel)ans+=Rdel-Ldel+1,print(i),psp,print(Rdel-Ldel+1),endl;
		}
		print(ans),endl;
	}
}

