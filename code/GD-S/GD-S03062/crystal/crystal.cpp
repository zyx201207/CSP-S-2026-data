#include<bits/stdc++.h>
using namespace std;
#define int long long
int maxn=0,n,m,sum=0;
vector<int> a(1000001,0);
void dfs(int step){
	if(step>m){
		int cnt=0;
		vector<int> a1(n+1);
		for(int i=1;i<=n;i++) a1[i]=a[i];
		sort(a1.begin()+1,a1.end());
		for(int i=1;i<=n;i++){
			if(a1[i]!=a1[i-1]) maxn=max(maxn,cnt),cnt=0;
			cnt++;
		}
		maxn=max(maxn,cnt);
		return ;
	}
	for(int i=1;i<=n;i++){
		a[i]++;
		dfs(step+1);
		a[i]--;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool sc=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) sc=false;
	}
	if(!sc){
		dfs(0);
		cout<<maxn;
	}else{
		int i;
		for(i=n;i>0;i++) if(sum+(n-i)>m) break;
		cout<<n-i+1;
	}
} 
