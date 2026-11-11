#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200008];
vector<int> s[200008];
bool vis[200008];
int num=0;
void choose(int m,int x){
	int ok=0;
	for(int i=1 ; i<=n ; i++){
		if(vis[i])ok++;
	}
	if(ok==m){
		++num;
		for(int i=1 ; i<=n ; i++){
			if(vis[i])s[num].push_back(a[i]);
		}
		return ;
	}
	if(x>n)return ;
	for(int i=x ; i<=n ; i++){
		if(!vis[i]){
			vis[i]=1;
			choose(m,i+1);
			vis[i]=0;
		}
	}
	return ;
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	for(int i=1; i <=n ; i++){
		cin >>a[i];
	}
	choose(m,1);
	int ans=-1;
	for(int i=1 ; i<=num ; i++){
		int res=s[i][0];
		for(int j=1 ; j<=s[i].size()-1 ; j++){
			res=(res & s[i][j]);
		}
		if(res>ans)ans=res;
	}
	cout <<ans;
	return 0;
} 
