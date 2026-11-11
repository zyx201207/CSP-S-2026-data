#include <iostream>
#include <map>
#include <cstdio>
#include <stack>
#define int long long
using namespace std;
int n,m,maxn,a[200005];
stack<int> s,p;
void dfs(int x,int cnt){
	if(x>n){
		if(cnt!=m) return ;
		int c;
		bool f=true;
		while(!s.empty()){
			int h=s.top();
			s.pop();
			p.push(h);
			if(f){
				f=false;
				c=h;
			}else{
				c&=h;
			}
		}
		maxn=max(maxn,c);
		while(!p.empty()){
			s.push(p.top());
			p.pop();
		}
		return ;
	}
	s.push(a[x]);
	dfs(x+1,cnt+1);
	s.pop();
	dfs(x+1,cnt);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==2){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
		return 0;
	}
	if(n<=20){
		maxn=0;
		dfs(1,0);
		cout<<maxn;
		return 0;
	}
	if(n==m){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn&=a[i];
		}
		cout<<maxn;
		return 0;
	}
	cout<<511;
	return 0;
}
