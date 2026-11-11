#include<bits/stdc++.h>
using namespace std;
#define maxn 5005
#define int long long

struct node{
	int x,y;
};

int c,t,n;
int lst[maxn],nxt[maxn],dp[maxn][3];
long long a[maxn],d;
queue<node> que[maxn][3];

void solve(){
	
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		lst[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
		nxt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		//cout<<nxt[i]<<" "<<endl;
	}
	
	/*
	int l=1,r=0;
	for(int i=2;i<=n;i++){
		while(r>=l && que[r].first>=dp[i-1]) r--;
		while(que[l].second<lst[i] && r>=l) l++;
		que[++r]={dp[i-1],i-1};
		dp[i]=que[l].first+1;
	}
	*/
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) for(int k=1;k<=2;k++) dp[j][k]=1e9;
		for(int j=1;j<=n;j++) for(int k=1;k<=2;k++) while(que[j][k].size()) que[j][k].pop();
		dp[i][1]=0;
		int l[3],r[3];
		l[1]=l[2]=1;
		r[1]=r[2]=0;
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=2;k++){
				while(r[k]>=l[k] && que[r[k]][k].front().x>dp[j-1][k]){
					while(que[r[k]][k].size()) que[r[k]][k].pop();
					r[k]--;
				}
				while(que[l[k]][k].front().y<lst[j] && r[k]>=l[k]){
					que[l[k]][k].pop();
					if(que[l[k]][k].size()==0) l[k]++;
				}
				if(que[r[k]][k].front().x==dp[j-1][k]) que[r[k]][k].push({dp[j-1][k],j-1});
				else que[++r[k]][k].push({dp[j-1][k],j-1});
			}
			if(que[l[1]][1].size()<=2) dp[j][que[l[1]][1].size()]=que[l[1]][1].front().x+1;
			if(que[l[2]][2].size()<=1) dp[j][2]=min(dp[j][2],que[l[2]][2].front().x+1);
		}
		int now=i,cnt=0;
		while(now!=n && nxt[now]!=now){
			cnt++;
			for(int j=now+1;j<=nxt[now];j++){
				if(dp[j][2]==cnt){
					ans++;
				}
			}
			now=nxt[now];
		}
	} 
	cout<<ans<<endl;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	
	cin>>c>>t;
	while(t--){
		solve();
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962

fc.exe D:\GD-S00436\subway\subway.out D:\GD-S00436\subway\subway7.ans
*/
