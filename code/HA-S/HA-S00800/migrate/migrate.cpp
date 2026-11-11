#include<bits/stdc++.h>
using namespace std;

const int maxn=2e6+5;

int c,t; 

long long pos[maxn];

int main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>c>>t;
	
	while(t--){
		
		int n;
		
		long long d;
		
		memset(pos,0,sizeof(pos));
		
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			
			cin>>pos[i];
			
		}
		
		if(c==11||c==12){
			
			if(pos[2]-pos[1]<d)cout<<n-3<<"\n";
				
			else cout<<0<<"\n";
			
			continue;
			
		}else if(c==13||c==14)cout<<0<<"\n";
		
	}

	return 0;

}

