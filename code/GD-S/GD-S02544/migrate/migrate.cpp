#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e3+5;

int c,T,n;
ll d,ans;
ll x[N];

int now,nnow;

void dfs(int u,int step,int goal){
	
	if(u==goal){
		if(now==0){
			now=step;
			nnow=1;
			return;
		}
		if(now>step){
			now=step;
			nnow=1;
		}
		else if(now==step){
			nnow++;
		}
	}
	
	if(step>=now&&now!=0) return;
	
	for(int i=goal;i>u;i--){
		if(x[i]-x[u]<=d){
			dfs(i,step+1,goal);
		}
	}
	
}

bool check(int s,int t){
	
	now=0;nnow=0;
	dfs(s,0,t);
	
	if(nnow==2) return 1;
	return 0;
}

void work(){
	ans=0;
	
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			if(check(i,j)) ans++;
		}
	}

	cout<<ans<<endl;
} 


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
	while(T--){
		
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		
		work();
	}
	
	return 0;
} 
