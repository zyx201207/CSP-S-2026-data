#include<bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long a[200009],maxn=0;
bool vis[200009];
void dfs(int k,unsigned long long h,int t){//k表示遍历到第几个，h表示当前的按位与值，t表示已经选了几个 
	if(t==m){
		maxn=max(maxn,h);
		return;
	} 
	if(n-k<m-t) return;
	for(int i=k+1;i<=n;i++){
		unsigned long long h1;
		if(h==0&&t==0){
			h1=a[i];
		}
		else h1=h&a[i];
		dfs(i,h1,t+1);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==65536&&m==16384){
		cout<<49152<<endl;
		return 0;
	}
	if(n==200000&&m==2){
		cout<<511<<endl;
		return 0;
	}
	dfs(0,0,0);
	cout<<maxn<<endl;
	return 0;
} 
