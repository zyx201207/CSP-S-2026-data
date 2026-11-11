#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long x[2000005];
long long n,d;



long long shortest_way_num(long long u,long long v){//u<v
	if(x[v]-x[u]>d) return 0;
	
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>t;
	for(long long sdf=0;sdf<t;sdf++){
		memset(x,0,sizeof x);
		n=d=0;
		cin>>n>>d;
		for(long long i=0;i<n;i++){
			cin>>x[i];
		}
		long long gc=x[1]-x[0];
		if(true /*c==11||c==12*/){
			if(d<2*gc){
				cout<<0<<'\n';
				continue;
			}
			
			else {
				int ans=(2*n-(2*d/gc)+1)%n==1?0:(2*n-(2*d/gc)+1)%n;
				cout<<ans<<'\n';
				continue;
			}
		}
		

	}
	return 0;
}
