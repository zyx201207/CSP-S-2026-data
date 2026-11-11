//GZ-J00721 贵阳市第三实验中学 刘子轩 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200003],maxx=-1;
bool v[200003];
void dfs(int k,int lastand){
	if(k==m){
		 maxx=max(maxx,lastand);
	}
	for(int i=k;i<n;i++){
		if(v[i]==0){
			v[i]=1;
			dfs(k+1,lastand&a[i]);
			v[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(v[i]==0){
			v[i]=1;
			dfs(1,a[i]);
			v[i]=0;
		}
	}
	cout<<maxx;
	return 0;
}

