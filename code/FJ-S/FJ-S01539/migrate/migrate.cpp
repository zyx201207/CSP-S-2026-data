#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,d,x[1000000],dis,ans,aa;
void dfs(int sp,int dd,int cnt){
	if(sp==dd){
		if(dis>cnt){
			ans=1;
			dis=cnt;
		}
		else if(dis==cnt){
			ans++;
		}
	}
	else{
		for(int i=sp+1;i<=dd;i++){
			if(x[i]-x[sp]<=d){
				dfs(i,dd,cnt+1);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		aa=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=0,dis=1e9;
				if(i!=j){
					dfs(i,j,0);
					if(ans==2) aa++;
				}
			}
		}
		cout<<aa<<"\n";
	}
	return 0;
}

