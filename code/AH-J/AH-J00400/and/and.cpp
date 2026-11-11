#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans;
void dfs(int i,long long x,int cnt){
	if(i==n+1&&cnt==m){
		ans=max(ans,x);
		return;
	}else if(n-i+1+cnt<m||cnt>m){
		return;
	}
	dfs(i+1,x,cnt);
	dfs(i+1,x&a[i],cnt+1);
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long q=(1<<30)-1;
	for(int i=1;i<=m;i++){
		q&=a[i];
	}
	if(m==1){
		cout<<a[1];
	}else if(m==2){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long x=a[i]&a[j];maxn=max(maxn,x);
			}
		}
		cout<<max(q,maxn);
	}else if(m==n){
		long long maxn=(1<<30)-1;
		for(int i=1;i<=n;i++)maxn&=a[i];
		cout<<max(q,maxn);
	}else if(m==n-1){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			long long h=(1<<30)-1;
			for(int j=1;j<=n;j++){
				if(h<maxn){
					h=0;
					break;
				}
				if(j==i)continue;
				h&=a[j];
			}
			maxn=max(maxn,h);
		}
		cout<<max(q,maxn);
	}else{
		long long maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		if(maxn<4){
			int cnt[4]={0};
			for(int i=1;i<=n;i++){
				cnt[a[i]]++;
			}
			if(cnt[3]>=m)cout<<3;
			else if(cnt[3]+cnt[2]>=m)cout<<2;
			else if(cnt[3]+cnt[1]>=m)cout<<1;
			else cout<<0;
		}else {
			dfs(1,(1<<30)-1,0);
			cout<<max(q,ans);
		}
	}
}
