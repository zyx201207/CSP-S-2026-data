#include<bits/stdc++.h>
using namespace std;
long long a[200005],out,k,ans,c[200005],cc;
int n,m,h[35],cnt,fcnt;
bool f[200005];
int b[200005][35];
priority_queue<long long> q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		f[i]=1;
	}
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long x=a[i];
		while(x){
			b[i][++b[i][0]]=x&1;
			x>>=1;
		}
		for(int j=1;j<=b[i][0];j++){
			h[j]=b[i][b[i][0]-j+1];
		}
		int k=1;
		for(int j=1;j<=b[i][0];j++){
			b[i][j]=0;
		}
		for(int j=31-b[i][0];j<=30;j++){
			b[i][j]=h[k];
			k++;
		}
	}
	for(int i=1;i<=30;i++){
		fcnt=0;
		for(int j=1;j<=n;j++){
			if(f[j]&&b[j][i]==1){
				fcnt++;
			}
		}
		if(fcnt>=m){
			for(int j=1;j<=n;j++){
				if(b[j][i]==0&&f[j]){
					f[j]=0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]){
			q.push(a[i]);
		}
	}
	while(!q.empty()&&cnt<m){
		int u=q.top();
		c[++cnt]=u;
		q.pop();
	}
	ans=c[1];
	for(int i=2;i<=cnt;i++){
		ans=ans&c[i];
	}
	cout<<ans;
	return 0;
}
