#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;

int n,m;
long long ans;
int a[N];
bool vis[N];

bool has(int x){
	int op=1ll<<x;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=op&&!vis[i]) cnt++;
	}
	return cnt>=m;
}

void solve(int x,bool y){
	int op=1ll<<x;
	for(int i=1;i<=n;i++){
		if(a[i]>=op){
			a[i]-=op;
		}else if(y) vis[i]=1;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=30;i>=0;i--){
		if(has(i)){
			ans+=(1<<i);
			solve(i,1);
		}else solve(i,0);
	}
	cout<<ans;
	
	return 0;
}
