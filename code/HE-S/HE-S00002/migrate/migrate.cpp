#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,xx[2000010],ans;
queue<pair<int,int>> que;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int T=1;T<=t;T++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>xx[i];
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=0,res=1e9;
				que.push({0,i});
				while(que.empty()==0){
					int distance=que.front().first,x=que.front().second;
					que.pop();
					if(distance>res){
						continue;
					}
					for(int k=1;k<=n;k++){
						if(llabs(xx[k]-xx[x])>d){
							continue;
						}
						if(k==j){
							if(distance+1<res){
								res=distance+1;
								cnt=1;
							}
							else if(distance+1==res){
								cnt++;
							}
						}
						que.push({distance+1,k});
					}
				}
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
