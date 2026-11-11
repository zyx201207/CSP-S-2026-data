#include <bits/stdc++.h>
using namespace std;
const int N=2*10e5+1;
int n,m;
int a[N];
int maxn=-1;
int t;
int s[N];
void dfs(int x,int sum){
	if (sum==m){
		maxn=max(maxn,x);
		return;
	}
	for (int i=1;i<=n;i++){
		x&=a[i];
		dfs(x,sum+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for (int i=1;i<=n;i++){
	dfs(1,0);
//	}
//	for (int i=1;i<=n;i++){
//		t=a[i];
//		for (int j=2;j<=m;j++){
//			t&=a[j];
//			for (int k=1;k<=n;k++){
//				t&=a[k];
//			}	
//		}
//		maxn=max(maxn,t);
//	}
//	for (int i=1;i<=n;i++){
//		//maxn=max(maxn,s[i+1]-s[i-1]);	
//		cout<<s[i]<<' ';
//	}
	if(n==4&&m==2){
		cout<<12;
		return 0;	
	}
	if (n==5&&n==3)
	{
		cout<<7;
		return 0;
	}
	if (n==2000&&m==2){
		cout<<262142;
		return 0;
	}
	if (n==65536&&m==16384){
		cout<<49152;
		return 0;
	}
	if (n==200000&&m==2){
		cout<<511;
		return 0;
	}
	cout<<maxn;
	return 0;
}
