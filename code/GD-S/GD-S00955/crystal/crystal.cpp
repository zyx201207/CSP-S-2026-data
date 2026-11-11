#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
int n,m,ans;
int b[N];
int checkh(){
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int cnt=1,ccnt=-1e18;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			cnt++;
		}else{
			ccnt=max(cnt,ccnt);
			cnt=1;
		}
	}
	return ccnt;
}
void dfs(){
	if(m==0){
		ans=max(ans,checkh());
		return;
	}
	for(int i=1;i<=n;i++){
		a[i]++;
		m--;
		dfs(); 
		a[i]--;
		m++;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=checkh();
	dfs();
	cout<<ans;
	return 0;
} 
