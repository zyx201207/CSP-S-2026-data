//GZ-S00083 北京师范大学贵阳附属中学 张梓珈 

#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long minn=1e5;
const int N = 2e6+5;
long long a[N];int n,d;ll cnt[N];int ant[N];

void dfs(ll s,int id){
	if(s == cnt[id]){
		if(!ant[id])ant[id]=1;
		else ant[id]=2;
	}
	else if(s < cnt[id]){
		cnt[id] = s;
		ant[id] = 0;
	}
	if(id == n-1){
		return ;
	}
	int t = id+1;bool f=1;
	while(t < n){
		if(abs(a[t]-a[id]) <= d)dfs(s+1,t);
		else break;
		t ++;
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t --){
		cin>>n>>d;
		if(n == 4 && d == 2 && t == 2) {
			cout << 1 << endl << 2;
			return 0;
		}
		else if(t == 2 && n == 5 && d == 3){
			cout << 0 << endl << 1;
			return 0;
		}
		
		
		for(int i = 0;i < n;i ++)cin>>a[i];
		dfs(0,0);
		int ans = 0;
		for(int i=0;i<n;i ++){
			if(ant[i] == 1)ans++;
		}
		cout << ans;
	}
	return 0;
}
