#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int w[N],x,y,t[505][N],a[505][N],n,m,d,q,ans=0;
vector<int>v[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)cin>>a[i][1]>>t[i][1]>>a[i][2]>>t[i][2];
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(x>y)swap(x,y);
		ans=w[x]+w[y]+t[x][2]+t[y][1];
		for(int j=x;j<=y;j++){
			ans+=t[j][2]+t[j+1][1];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
