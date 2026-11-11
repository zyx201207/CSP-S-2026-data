#include <bits/stdc++.h>
using namespace std;
int ccsz[200005];
int sz[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int n,m;//给你n个值，你只能用m个
	cin>>n>>m; 
	
	//输入
	for(int i = 1;i <= n;i++){
		cin>>ccsz[i];
	}
	
	sort(ccsz+1,ccsz+n+1);//排序
	
	int z = 1;
	for(int i = n-m+1;i <= n;i++){
		sz[z] = ccsz[i];
		z++;
	} 
	
	int jh = sz[1];
	for(int i = 2;i <= m;i++){
		jh= jh&sz[i];
	}
	cout<<jh;
	return 0;
}
