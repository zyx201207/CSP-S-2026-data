#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t;
struct Node{
	int num;
	string v;
};
string a[N];
vector<Node> b[N];
int ans;
void dfs(int l,int r,int w,int dp,string sum){
	if(l>r){
		return;
	}
	b[l].push_back({dp,sum});
	for(int i=1;i<=w;i++){
		dfs(l+i,r,w,dp+1,sum+a[l+i]);
	}
}
signed main()
{
	cin>>c>>t;
	while(t--){
		int n,k;
		ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				while(!b[j].empty()){
					b[j].pop_back();
				}
			}
			dfs(i,n,k,0,a[i]);
			for(int j=i;j<=n;j++){
				if(b[j].size()>=2){
					bool flag=0;
					int tmp1=b[j][0].num;
					string tmp2=b[j][0].v;
					for(int z=1;z<b[j].size();z++){
						if(b[j][z].num==tmp1&&b[j][z].v!=tmp2){
							flag=1;
							break;
						}
					}
					if(flag){
						ans++;
					}
				}
			}
		}
		cout<<ans;
	}
	
	return 0;
}
