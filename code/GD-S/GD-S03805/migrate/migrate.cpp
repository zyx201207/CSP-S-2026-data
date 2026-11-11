#include <bits/stdc++.h>
using namespace std;
const int N=3000005;
long long xx[N];	
long long n,d,sum=0;

int f(int st,int en){
	if(st== en-1){
		return 1;
	}
	else if(abs(xx[en]-xx[st])<=d){
		return 1;
	}
	return f(st,en-1)+f(en-1,en);
	
}

int main (){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t,cnt=0,un=0;bool is_A=1,is_B=1;
	cin>>c>>t;
	

	
	while(t--){
		
		cin>>n>>d;sum=0,un=0;
		
		memset(xx,0,sizeof(xx));
		for(int i=1;i<=n;i++){
			cin>>xx[i];
		}	
		
		int s=xx[2]-xx[1];
		for(int i=2;i<=n;i++){
			if(xx[i]-xx[i-1]!=s){
				is_A=0;
			}
		}
	
		if(is_A){
			
			for(int i=1;i<=n;i++){
				for(int j=n;j<=i+1;j++){
					un=f(i,j);
					if(xx[j]-xx[i]<=d){
						cnt+=min(f(i,j),f(j,n));
					} 
					if(un!=cnt){
						sum++;
					}
				}
			}
		
		}
		cout<<sum<<'\n';

	}
	
	return 0;
}






 
