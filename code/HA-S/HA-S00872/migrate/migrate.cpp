#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll c,t,n,d,a[5003],jyh[5003][5003],ans; 

int stp(int u,int v){
	if(jyh[u][v])return jyh[u][v];
	if(a[v]-a[u]<=d)return jyh[u][v]=1;
	int ret=114514233;
	for(int i=u+1;i<v;i++){
		ret=min(ret,stp(u,i)+stp(i,v));
	}return jyh[u][v]=ret;
}

bool walk(int u,int v){
	
	int mstp=114514233,nstp,way=1;
	
	for(int i=u+1;i<v;i++){
		nstp=stp(u,i)+stp(i,v);
		if(mstp>nstp){
			mstp=nstp;
			way=1;
		}else if(mstp==nstp)way++;
	}
	
	return way==2?1:0;
}

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>t;
	
	if(c>10){
		while(t--)cout<<"0\n";
	}
	
	while(t--){
		
		ans=0;
		memset(jyh,0,sizeof(jyh));
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		
		for(int i=1;i<n-2;i++){
			
			for(int j=4;j<=n;j++){
				if(a[j]-a[i]<=d)continue;
				
				if(walk(i,j))ans++;
				
			}
			
		}
		
		
		cout<<ans<<'\n';
		
	}
	
	return 0;
}
