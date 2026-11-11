#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int ans;
void dfs (int num,int x,int mm){
	//cout<<num<<" "<<x<<" "<<mm<<"\n";
	if (mm>=m){
		ans=max(ans,num);
		return;
	}
	if (x>n)return;
	if (mm<m){
		dfs(num&a[x],x+1,mm+1);
		dfs(num,x+1,mm);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		dfs(a[i],i+1,1);
	}
	
	cout<<ans;
}

