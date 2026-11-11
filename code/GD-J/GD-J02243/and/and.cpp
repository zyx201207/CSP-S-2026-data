#include<bits/stdc++.h>
using namespace std;
int a[1000010],m,t[10010010];
int ans,mx=-1,n;
string s[1000010];
void dfs(int i,int id,int now){
	if(id>=m){
		mx=max(mx,now);
		return ;
	}
	int mm=-1;
	for(int j=i+1;j<=n;j++)dfs(j,id+1,now&a[j]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m+1==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		
		for(int i=1;i<=n;i++)mx=max(mx,ans&a[i]);
		cout<<mx;
		return 0;
	}
	
	for(int i=1;i<=n-m;i++){
		dfs(i,1,a[i]);
	}
	cout<<mx;
	return 0;
} //Trick||Treat!
