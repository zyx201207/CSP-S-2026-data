#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int c,t,d[100001],n,f[100001];
long long a[100001],s;
void dfs(int x){
	d[x]++;
	if(a[x]==a[n]){
		return;
	}
	for(int i=n;i>x;i--){
		if(a[i]-a[x]<=s&&f[i]==0){
			f[i]=1;
			dfs(i);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int sum=0;
		cin>>n>>s;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			dfs(i);
		}
		for(int i=1;i<=n;i++){
			if(d[i]==2){
				sum++;
			}
			d[i]=0;
			f[i]=0;
		}
		cout<<sum/2<<endl;
	}
	return 0;
}

