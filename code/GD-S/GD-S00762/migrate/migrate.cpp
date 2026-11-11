#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,sum,a[2000008];
bool isf=0;
int maxx=0;
void dfs(int x,int f,int w){
	if(x==f){
		if(isf==1){
			isf=0;
			maxx=w;
			sum++;
//			cout<<"maxx="<<w<<'\n';
			return;
		}
		else{
			if(w==maxx){
				sum++;
			}
			return;
		}
	}
	int sum=0;
	for(int i=f;i>x;i--){
		if(a[i]-a[x]<=d){
//			cout<<i<<' '<<f<<' '<<w+1<<' '<<sum<<' '<<'\n';
			dfs(i,f,w+1);
		}
	}
	return;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			isf=1,maxx=0,sum=0;
			dfs(i,j,0);
//			cout<<i<<' '<<j<<' '<<maxx<<'\n';
			if(sum==2){
				cnt++;
			}
			
		}
	}
	cout<<cnt<<'\n';
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
