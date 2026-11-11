#include <bits/stdc++.h>
using namespace std;
 
long long T,n,d,q,ans;
long long a[2000005];
int b[305][305];int p[305];
bool shuangj(int x,int y){
	memset(p,0,sizeof p);
	if(a[y]-a[x]<=d)return false;
	if((a[y]-a[x])%d==0)return false;
	int pos=x;p[pos]=1;
	for(int i=x+1;i<=y;i++){
		if(a[i+1]-a[i]>d)return false;
		if(b[x][i]&&b[i][y])return false;
		while(p[i]-p[pos]>d)pos++;
		if(i==y){for(int j=pos;j<=i;j++){p[i]+=p[j];}}
		else p[i]+=p[pos];
	}
	if(p[y]>2){b[x][y]=2;return false;}
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;ans=0;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(shuangj(i,j)){
					b[i][j]=1,ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
