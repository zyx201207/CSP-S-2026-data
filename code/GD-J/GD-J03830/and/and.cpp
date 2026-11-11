#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 2e5 + 5;
long long a[Maxn];
int mx_ans = -1;
int n,m;

void DFS(int p,int cnt,int ans){
	if(cnt == m){
		mx_ans = max(mx_ans,ans);
		return;	
	}
	for(int i=p;i<=n;i++){
		DFS(i+1,cnt+1,int(ans & a[i]));
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-m+1;i++){
		DFS(i+1,1,a[i]);
	}
	cout<<mx_ans;
	return 0;
}
