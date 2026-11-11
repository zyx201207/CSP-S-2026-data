#include <bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[200005];
int mx[200005];
void dfs(int x,int nm,int cnt){
	cout<<"x="<<x<<" nm="<<nm<<" cnt="<<cnt<<endl;
	if(nm==m){
		cout<<"cnt="<<cnt<<endl;
		ans=max(ans,cnt);
		return;
	}
	if(x==n+1)return;
	if(nm==0){
		dfs(x+1,nm+1,cnt+a[x]);		
	}else{
		dfs(x+1,nm+1,cnt&a[x]);
	}
	dfs(x+1,nm,cnt);
}
int main(){ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int v=1;
		while(a[i]){
			if(a[i]>=v){
				a[i]-=v;
			}else{
				v=a[i];
				a[i]-=v;
			} 
			mx[v]++; 
			v*=2;
		}
	}
	//dfs(1,0,0);
	int num=0;
	for(int i=32;i>=1;i--){
		//if(mx[i]==0)continue;
		if(mx[i]>=m){
			ans+=i;
			num++;
		}		
	}
	cout<<ans;
} 
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
