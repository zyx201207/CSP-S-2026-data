#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int ans;
void sol(int v,int pre){
	if(v==-1){
		ans=pre;
		return;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if((pre&a[i])!=pre) continue;
		if(a[i]&(1<<v)) cnt++;
	}
	if(cnt>=m) sol(v-1,pre|(1<<v));
	else sol(v-1,pre);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sol(29,0);
	cout<<ans<<'\n';
}
