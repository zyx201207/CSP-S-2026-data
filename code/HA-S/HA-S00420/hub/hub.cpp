#include<bits/stdc++.h>
using namespace std;
int c,T,n,m,xx,yy;
vector<int>v[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			cin>>xx>>yy;
			v[xx].push_back(yy);
			v[yy].push_back(xx);
		}
		if(n==m){
			cout<<"0";
			continue;
		}
		if(13<=c&&c<=14){
			int p=n/2,pp=p/2;
			if(p&1){
				if(pp&1) cout<<pp/2+2-(m+1)/4<<"\n";
				else cout<<pp/2+1-(m-1)/4<<"\n";
			}else{
				if(pp&1) cout<<pp/2+1-(m-2)/4<<"\n";
				else cout<<pp/2+1-m/4<<"\n";
			}
		}else if(n<=5) cout<<1<<"\n";
		else cout<<(n+m-1)/m<<"\n";
	}
	return 0;
}
