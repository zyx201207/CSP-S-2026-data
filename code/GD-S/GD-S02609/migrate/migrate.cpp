#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+10;
int z[maxn];
int c,tt,n,dd;
int cnt;
int st,en;
int mi;
void dfs(int d,int x){
	if(d==en){
//		cerr<<"get the end! "<<cnt<<endl;
		if(x<mi){
			mi=x;
			cnt=1;
		}else if(x==mi){
			cnt+=1;
		}return ;
	}
	for(int i=d+1;i<=en;i++){
		if(z[i]-z[d]<=dd){
//			cerr<<d<<" "<<i<<endl;
			dfs(i,x+1);
		} 
	}return ;
}void b1(){//8pts
	while(tt--){
		cin>>n>>dd;
		for(int i=1;i<=n;i++){
			cin>>z[i];
		}int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				cnt=-1;
				st=i,en=j;
				mi=INT_MAX;
				dfs(st,0);
				if(cnt==2){
					ans+=1;
//					cerr<<i<<" "<<j<<endl;
				}
			}
		}cout<<ans<<endl;
	}return ;
}
signed main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>tt;
	if(c==11||c==12){
		while(tt--){
			cin>>n>>dd;
			for(int i=1;i<=n;i++){
				cin>>z[i];
			}int c=z[2]-z[1];
			int p=dd/c;
			cout<<n-1-p<<endl;
		}
	}else{
		b1();
	}
	return 0;
}
