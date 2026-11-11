#include<bits/stdc++.h>
#define intt long long
using namespace std;
intt c,t;
intt a[2000006];
intt n,d;
intt minn=LONG_LONG_MAX,cnt=0;
void dfs(intt x,intt y,intt s){
	if(x==y){
		if(minn>s){
			minn=s;
			cnt=1;
		}else if(minn==s){
			cnt++;
		}
		return ;
	}
	if(s>=minn){
		return ;
	}
	intt v=x+1;
	while(((a[v]-a[x])<=d) && v<=y){
		dfs(v,y,s+1);
		v++;
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	
	while(t--){
		
		cin>>n>>d;
		
		
		for(intt i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n>=2e6){
			cout<<"0\n";
			continue;
		}
		intt ans=0;
		for(intt i=1;i<=n;i++){
			for(intt j=i+1;j<=n;j++){
				if(i!=j){
					minn=LONG_LONG_MAX;
					cnt=0;
					dfs(i,j,0);
					if(cnt==2){
						ans++;
					}
				}
			}
		} 
		cout<<ans<<"\n";
	}
	return 0;
} 
