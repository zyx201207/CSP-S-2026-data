#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,m,v,b;
long long a[N];
long long dfs(long long x,long long y,long long ans){
	if(y==m) return ans;
	b=0;
	for(int i=x+1;i<=n-m+y+1;i++){
		b=max(b,dfs(i,y+1,a[i]&ans));
	} 
	return b;
}
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m==1){
		long long maxn=0;
		while(n--){
			cin>>v;
			maxn=max(maxn,v);
		}
		cout<<maxn;
	}
	else if(m==n){
		n--;
		int ans;
		cin>>ans;
		if(n--){
			cin>>v;
			ans=ans&v;
		}
	}
	else if(n<=20){
		long long maxn=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) {
			maxn=max(maxn,dfs(i,1,a[i]));
		}
		cout<<maxn;
	}
	else cout<<"老板给我来碗忘情牛肉面，不放牛肉不放葱花，不放忘情汤，这回忆的漩涡，快要把我吞没，被比我去吧瞬间就爱上雷神，等下一个天亮";
}
