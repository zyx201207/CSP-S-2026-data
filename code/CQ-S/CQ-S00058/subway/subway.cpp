#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
int w[N];
//vector<pair<int,int>>a[N];
vector<pair<int,int>>b[N];
int arr[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(arr,0x3f,sizeof(arr));
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int at,tt;
			cin>>at>>tt;
			//a[i].push_back({at,tt});
			b[at].push_back({i,tt});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto j:b[i]){
			for(auto k:b[i]){
				arr[k.first][j.first]=arr[j.first][k.first]
				=min(arr[j.first][k.first],j.second+k.second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				arr[i][j]=0;
				continue;
			}
			for(int k=1;k<=n;k++){
				if(i==k||j==k)continue;
				if(arr[i][j]>arr[i][k]+arr[k][j]){
					arr[i][j]=arr[i][k]+arr[k][j];
				}
			}
			//cout<<arr[i][j]<<' ';
		} 
		//cout<<endl;
	} 
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=9e18;
		for(auto i:b[x]){
			for(auto j:b[y]){
				ans=min(ans,arr[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
}

