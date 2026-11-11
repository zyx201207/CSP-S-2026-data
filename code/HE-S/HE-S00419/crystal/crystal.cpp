#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1e12;
long long a[500010];
void dfs(long long num){
	if(num==m+1){
		long long cnt=1,nowmaxn=-1e12;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				cnt++;
				nowmaxn=max(nowmaxn,cnt);
			}
			else{
				nowmaxn=max(nowmaxn,cnt);
				cnt=1;
			}
		}
		maxn=max(maxn,nowmaxn);
		return;
	}
	for(int i=1;i<=n;i++){
		a[i]++;
		dfs(num+1);
		a[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<maxn;
	
	return 0; 
}
