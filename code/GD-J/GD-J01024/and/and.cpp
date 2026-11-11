#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s,maxx,ans;
bool flag=1;
int q[200005],h[200005];
int a[200005];
void dfs(int now,int si,int j){
	if(si==m){
		ans=max(ans,j);
		return ;
	}
	if(now>n) return ;
	dfs(now+1,si+1,j&a[now]);
	dfs(now+1,si,j);
}
bool check(int x){
	int l=0,r=30;
	while(l<=r){
		int mid=(l+r)>>1;
		if((1<<mid)==x) return true;
		if((1<<mid)>x) r=mid-1;
		else l=mid+1;
	}
	return false;
}
bool cmp(int s1,int s2){
	return s1>s2;
}
signed main(){//75pts
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i],s&=a[i],maxx=max(maxx,a[i]);
		if(!check(a[i]+1)) flag=0;
	}
	if(n==m){//7
		cout<<s;
	}
	else if(n-1==m){//11,12
		q[0]=INT_MAX;
		h[n+1]=INT_MAX;
		for(int i=1;i<=n;i++) q[i]=q[i-1]&a[i];
		for(int i=n;i>=1;i--) h[i]=h[i+1]&a[i];
		for(int i=1;i<=n;i++){
			ans=max(ans,q[i-1]&h[i+1]);
		}
		cout<<ans;
	}
	else if(flag){//13
		sort(a+1,a+n+1,cmp);
		ans=INT_MAX;
		for(int i=1;i<=m;i++) ans=min(ans,a[i]);
		cout<<ans;
	}
	else if(n<=20){//1~5
		dfs(1,0,INT_MAX);
		cout<<ans;
	}
	else if(m==1){//6
		cout<<maxx;
	}
	else if(m==2){//8~10
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(maxx<4){//16,17
		int u[5];
		memset(u,0,sizeof(u));
		for(int i=1;i<=n;i++){
			u[a[i]]++;
		}
		if(u[3]>=m) cout<<3;
		else if(u[2]+u[2]>=m) cout<<2;
		else if(u[1]+u[3]>=m) cout<<1;
		else cout<<0;
	}
	return 0;
}

