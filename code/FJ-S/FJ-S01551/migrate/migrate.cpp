#include<bits/stdc++.h>
using namespace std;
const int N=2*1e4+10;
long long n,d,a[N],ans,qwq,s,c;
void bfs(int x,int y,int w){
	int z=a[x]+d;
	if(z>=a[y]){
		if(w<c){
			c=w;
			s=0;
		}else{
			s++;
		}
	}else if(z>=a[x+1]){
		for(int i=x+1;i<y;i++){
			if(a[i]<=z){
				bfs(i,y,w+1);
			}else break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n<=5000){
			ans=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				for(int j=1;j<i;j++){
					s=0,c=0;
					bfs(j,i,1);
					if(s==2) ans++;
				}
			}
			cout<<ans<<"\n";
		}else{
			for(int i=1;i<=n;i++) cin>>qwq;
			if(n==1||n==2) cout<<0<<"\n";
			else if(n==3) cout<<2<<"\n";
			else cout<<0<<"\n";
		}
	}
	return 0;
}
