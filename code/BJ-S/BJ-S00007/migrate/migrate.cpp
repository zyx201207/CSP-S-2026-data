#include<bits/stdc++.h>
using namespace std;
int n,d;
int a[2000006];
int minn=1e9,cnt;
void check(int l,int r,int cur,int step){
	if(cur==r){
		if(minn>step){
			minn=step;
			cnt=1;
		}
		else if(minn==step){
			cnt++;
		}
		return;
	}
	for(int i=cur+1;i<=r;i++){
		if(a[i]-a[cur]>d) break;
		check(l,r,i,step+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	if(c>=11&&c<=12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int c=a[2]-a[1];
			if(d<2*c||d>=3*c){
				cout<<0<<"\n";
			}
			else{
				cout<<n-3<<"\n";
			}
		}
	}
	else{
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int ans=0;
			for(int l=4;l<=n;l++){
				for(int u=1;u+l-1<=n;u++){
					int v=u+l-1;
					if(a[v]-a[u]<=d) continue;
					minn=1e9,cnt=0;
					check(u,v,u,0);
					if(cnt==2){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}
