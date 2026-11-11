#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define mp make_pair
using namespace std;
using pr=pair<int,int>;

const int N=305;

int c,n,m,T,k,x,y;
vector<int> a[N];
int st[305][305];
long long w[N],cnt[305][305],dis,ans;
long long d[305][305];

void floyd(){
	memset(cnt,0,sizeof(cnt));
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(d[i][k]+d[k][j]<d[i][j]){
					d[i][j]=d[i][k]+d[k][j];
					cnt[i][j]=1;
				}
				else if(d[i][k]+d[k][j]==d[i][j]){
					cnt[i][j]++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==3) ans++;
		} 
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>dis;	
		for(int i=1;i<=n;i++){
			cin>>w[i];	
		}
		memset(d,0x3f,sizeof(d));
		for(int i=1;i<=n;i++){
			d[i][i]=0;
			for(int j=1;j<i;j++){
				if(w[i]-w[j]<=dis) d[j][i]=1;
			}
			for(int j=i+1;j<=n;j++){
				if(w[j]-w[i]<=dis) d[i][j]=1;
			}
	
		}
		ans=0;
		floyd();
		cout<<ans<<endl;
	}
	return 0;
}
