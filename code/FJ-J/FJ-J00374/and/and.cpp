#include<bits/stdc++.h>
using namespace std;
long long n,m,mx=0;
vector<long long> a(100005,0);
void dfs(long long pos,long long sum,long long we){
	if(pos<=n && we==m){
		mx=max(mx,sum);
	}else if(pos>n){
		return;
	}
	dfs(pos+1,sum,we);
	if(we==0){
		dfs(pos+1,a[pos],we+1);
	}
	else{
		dfs(pos+1,(sum&a[pos]),we+1);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(nullptr);
	cin.tie(false);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<mx;
	return 0;
}
