#include <bits/stdc++.h>
using namespace std;
int a[2000010];
int b[2000010];
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			b[i]=a[n]-a[i];

		}
		
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				queue<pair<int,int>>q;
				q.push({i,0});
				int ant=0,cntt=-1;
				while(q.size()){
					pair<int,int>p=q.front();
					int x=p.first,y=p.second;
					q.pop();

					if(x>j)continue;
					else if(x==j){
						
						if(cntt==-1||cntt>y){
							cntt=y;ant=0;
						}
						if(cntt==y)ant++;
					
					}
					for(int t=x+1;t<=n;t++){
						if(abs(b[t]-b[x])<=d)
						q.push({t,y+1});
						else break;
					}
				}
				if(ant==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
} 
