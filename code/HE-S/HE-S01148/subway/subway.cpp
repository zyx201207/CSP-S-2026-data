#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;
const int M=5e5+5;
int c,n,m,d,q;

int w[M];
struct sub{
	int a,t;
}b[N][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=1;j<=l;j++){
			cin>>b[i][j].a>>b[i][j].t;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=0;
		for(int i=1;i<=m;i++){
			if(i==x){
				ans+=w[i];
			}
			if(i==y){
				ans+=w[i];
			}
		}
		int dot[M];
		int cnt=0;
		for(int i=1;i<=n;i++){
			int k=l;
			for(int j=1;j<=k;j++){
				if(b[i][j].a==x){
					ans+=b[i][j].t;
				}
				if(b[i][j].a==y){
					ans+=b[i][j].t;
				}
				if(y-x>0){
					for(int k=x+1;k<=y;k++){
						if(dot[k]==b[i][j].a&&cnt<=d){
							ans+=b[i][j].t;
							cnt++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

