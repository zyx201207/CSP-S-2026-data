#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,as,a[N];

bool vis[N];
void dfs(int p,long long s){
	if(p>m){
		as=max(as,s);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&int(s&a[i])>=s){
			vis[i]=1;
			dfs(p+1,int(s&a[i]));
			vis[i]=0;
		}
	}
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(2,a[i]);
		vis[i]=0; 
	}
	cout<<as<<endl;
	return 0;
}
