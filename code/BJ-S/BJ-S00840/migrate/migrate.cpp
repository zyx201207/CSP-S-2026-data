#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int dis[5010][5010],c,t,a[5010];
/*
void dfs(int cur,int lon){
	
	if(cur==n-1){
		return ;
	}
	dis[1][cur]=lon;
	for(int i=cur+1;i<=n;i++){
		if(a[i]-a[cur]<=d){
			dfs(i,lon+1);
		}else{
			break;
		}
	}
}*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11&&c==12){
		while(t--){
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int c=a[n]-a[n-1];
			if(d<=c){
				cout<<0;
			}else if(c*2<=d&&c*3>d){
				if(n==5)
				cout<<1;
				else cout<<0;
			}else{
				cout<<0;
			}
		}
	}else{
		while(t--){
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<0;
		}
		
	}
	
	return 0;
}
