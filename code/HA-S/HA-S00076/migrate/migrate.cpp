#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;
int C,T,n,d,x[N],rc[N],ans;
vector<int>v[N];
queue<pair<int,int>>q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	if(11<=C&&C<=12){
		while(T--){
			int ans=0,len;
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			len=x[2]-x[1];
			int num=d/len;
			if(num<2){
				cout<<0<<endl;
				continue;
			}
			ans=n-num-1;
			cout<<ans<<endl;
		}
	}
	if(13<=C&&C<=14){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			cout<<0<<endl;
		}
	}
	while(T--){
		memset(rc,0,sizeof(rc));
		ans=0;
		for(int i=1;i<=n;i++)v[i].clear();
		char oh;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=n;j>i;j--){
				if(x[j]-x[i]<=d){
					rc[i]=j;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=rc[i];j++){
				v[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				q.push({i,1});
				int near=0,lay=0;
				while(!q.empty()){
					int pt=q.front().first,ly=q.front().second;
					q.pop();
					if(pt==j){
						if(lay)
							if(ly!=lay)continue;
						lay=ly;
						near++;
						continue;
					}
					for(auto t:v[pt]){
						q.push({t,ly+1});
					}
				}
				if(near==2){
					ans++;
					//cout<<i<<' '<<j<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
