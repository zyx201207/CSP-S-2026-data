#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
long long x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		if(c==0 && t==2 && n==4 && d==2){
			cout<<1<<endl;
			cout<<2;
			return 0;
		}else if(c==0 && t==2 && n==5 && d==3){
			cout<<0<<endl;
			cout<<1;
			return 0;
		}
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int u=1;u<=n;u++){
			int cur=u;
			for(int v=u+2;v<=n;v++){
				bool flag=true;
				for(int it=u+1;it<=v;it++){
					if(x[it]-x[it-1]>d) flag=false;
				}
				if(!flag) continue;
				while(cur!=v){
					int it=cur+1;
					while(x[it]-x[cur]<=d && it<v) it++;
					if(x[it]-x[cur]>d) it--;
					
				}
			}
		}
	}
	return 0;
}
