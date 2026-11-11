#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10,inf = 0x3f3f3f3f;
int a[N],n,m,ans = -inf;
int find(){
	int cnt = 0;
	int b[N];
	for(int i = 1;i<=n;i++) b[i] = a[i];
	sort(b+1,b+1+n);
	for(int i = 1;i<=n;i++)
		if(b[i] == b[i+1]) cnt++;
	return cnt;
}
void solve(int u,int cost){
	if(u > n || cost > m){
		ans = max(ans,find());
		return;
	}
	for(int i = 0;i<=m;i++){
		a[u]+=i;
		solve(u+1,cost+i);
		a[u]-=i;
	}
}
void solve2(){
	int b[N];
	b[2] = 1;
	bool flag3 = 0;
	for(int i = 3;i<=n;i++){
		b[i] = b[i-1] + a[i-1];
		if(b[i] > m){
			cout<<b[i-1];
			flag3 = 1;
			break;
		}
	}
	if(!flag3)cout<<b[n];
}
void solve3(){
	int b[N];
	b[2] = a[2]-a[1];
	int nb = b[2];
	bool flag3 = 0;
	for(int i = 3;i<=n;i++){
		b[i] = b[i-1] * nb;
		if(b[i] > m){
			cout<<b[i-1];
			flag3 = 1;
			break;
		}
	}
	if(!flag3)cout<<b[n];
}
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal3.out","w",stdout);
	cin>>n>>m;
	bool flag = 1,flag2 = 1;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i] != i)flag = 0;
		if(a[i]-a[i-1] != a[i-1]-a[i-2]) flag2 = 0;
	}
	if(flag){
		solve2();
		return 0;
	}
	if(flag2){
		solve3();
		return 0;
	}
	solve(1,0);
	cout<<ans;
	return 0;
}

