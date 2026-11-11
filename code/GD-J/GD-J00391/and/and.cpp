#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m,a[200005];
bool vis[200005];
long long ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	memset(vis,true,sizeof(vis));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=31;i>=1;i--){
		int num=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==false){
				continue;
			}
			if(a[j] & (1<<(i-1))){
				num++;
			}
		}
		if(num<m){
			continue;
		}
		
		for(int j=1;j<=n;j++){
			if(vis[j]==false){
				continue;
			}
			if( (a[j] & (1<<(i-1)) ) == 0){
				vis[j]=false;
			}
		}
		
		ans+=(1<<(i-1));
	}
	cout<<ans;
	return 0;
}










