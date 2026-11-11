#include<bits/stdc++.h>

using namespace std;
const int N=2e6+7;
int n,a[N],t,d,c,idx,cnt,f[N];
void dfs(int x,int n){
	if(x==n){
		f[n]++;
		return ;
	} 
	for(int i = x+1 ; i <= n ; i++){
		if(a[i]-a[x]<=d){
			dfs(i,n);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cnt=0;
		for(int i = 1 ; i <= n ; i++){
			cin>>a[i];
		}
		for(int i = 1 ; i <= n ; i++){
			for(int j = i+1 ; j <= n ; j++){
				dfs(i,j);
				if(f[j]==2) cnt++;
				f[j]=0;
			}
		}
		cout<<cnt<<"\n";
	}
	
	return 0;
}

