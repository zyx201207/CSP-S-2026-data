#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n,d,x[100001];
//ÍÆÏú£ºluogu.com.cn/team/106372 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;for(int i=1;i<=n;i++)cin>>x[i];
		int ans=0;
		for(int u=1;u<=n;u++){	
			int cnt=0;		
			for(int v=u+1;v<=n;v++){
			//	if(u+d>=v)cnt++;
				for(int i=u;i<=v;i++){
					if(u+d>=i && i+d>=v)
					{
						cnt++;
					//	cout<<"u="<<u<<" v="<<v<<" i="<<i<<" d="<<d<<'\n';
					}
				}	
										
			}
			if(cnt==2)ans++;	
		}
		cout<<ans<<'\n';
	}
}
