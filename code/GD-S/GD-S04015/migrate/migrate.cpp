#include<bits/stdc++.h>
#define ll long long
using namespace std;
map <int,int>mp;
int a[2000005];
bool b[2000005];
void dfs(int dep,int d,int n){
	if(dep>n){
		return;
	}
	for(int i=dep+1;i<=n;i++){
		if(a[dep]+d>=a[i]){
			mp[i]++;
			dfs(i,d,n);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,t;
	cin>>c>>t;
	for(int q=1;q<=t;q++){
		int n,d,cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=0;
			mp[i]=0;
		}
		dfs(1,d,n);
		for(int i=1;i<=n;i++){
			if(mp[i]==2)cnt++;
		}
		cout<<cnt<<'\n';;
	} 
	return 0;
}

