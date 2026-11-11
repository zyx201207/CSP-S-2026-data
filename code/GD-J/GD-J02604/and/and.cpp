#include<bits/stdc++.h>
using namespace std;

const int N=2e5+3;
long long n,a[N],s,m;
bool f[N];
/*
int dfs(int k,int num){
	if(k==m){
		return num;
	}
	int mac=-11;
	for(int i=1;i<=n;i++){
		if(f[i]==1){
			continue;
		}
		f[i]=1;
		int x=dfs(++k,num&a[i]);
		f[i]=0;
		mac=max(x,mac);
	}
	return mac;
} */

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	/*int mac=-1;
	for(int i=1;i<=n;i++){
		f[i]=1;
		int x=dfs(1,a[i]);
		f[i]=0;
		mac=max(x,mac);
	}cout<<mac;*/
	sort(a+1,a+n+1);
	int y=a[n];
	for(int i=n-1;i>=n-m;i--){
		y=y&a[i];
	}cout<<y;
	return 0;
}/*4 2
3 15 12 12*/
