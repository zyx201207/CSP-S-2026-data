#include<bits/stdc++.h>
using namespace std;

const int N=2e5+9;
int n,m,a[N];

int check(int bit){
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(a[i]&(1<<(bit-1))) cnt++;
	return cnt;
}

int lowbit(int x){
	return x&-x;
}

struct cmp{
	bool operator()(int a,int b) const{
		return lowbit(a)<lowbit(b);
	}
};
priority_queue<int,vector<int>,cmp> q;

void solve1(){
	int ans=0;
	for(int i=1;i<(1<<n);i++){
		if(__builtin_popcount(i)==m){
			int res=(1<<n)-1;
			for(int j=0;j<n;j++)
				if(i&(1<<j)) res&=a[j];
			ans=max(ans,res);
		}
	}
	cout<<ans<<'\n';
}

void solve2(){
	for(int i=30;i>=1;i--){
		if(check(i)>=m){
			for(int j=1;j<=n;j++)
				if(a[j]&(1<<(i-1))) q.push(a[j]);
			int ans=(1<<30)-1;
			for(int j=1;j<=m;j++){
				ans&=q.top();
				q.pop();
			}
			cout<<ans<<'\n';
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20) solve1();
	else solve2();
	return 0;
}

