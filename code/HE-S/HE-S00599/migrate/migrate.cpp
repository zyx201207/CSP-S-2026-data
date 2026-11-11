#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long x[N];
long long n,d;
bool h[N];
bool bfs(long long a,long long b){
	queue<int> dpa;
	queue<int> dpb;
	long long anss=0,minn=1e18;
	dpa.push(a);
	dpb.push(0);
	for(int i=1;i<=n;i++){
		h[i]=0;
	}
	while(dpa.size()){
		int dp=dpa.front();
		int p=dpb.front();
		dpa.pop();
		dpb.pop();
		h[dp]=1;
		for(int i=1;x[i+dp]-x[dp]<=d&&dp+i<=n;i++){
			int ii=i+dp;
			if(ii==b&&minn==1e18){
				anss++;
				minn=p;
			}else if(ii==b&&minn==p){
				anss++;
			}else if(h[ii]==0){
				dpa.push(ii);
				dpb.push(p+1);
			}
		}
	}
	return anss==2;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
    	long long w=0;
    	cin >> n >> d;
    	for(long long i=1;i<=n;i++){
    		cin >> x[i];
		}
		for(long long i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(bfs(i,j)){
					w++;
				}
			}
		}
		cout <<w<<endl;
	}
	return 0;
}
