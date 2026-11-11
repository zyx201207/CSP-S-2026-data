#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long x[2000005];
long long l,len;
long long dis[305][305];
long long cnt[305][305];
long long ans;
void solveA(){
	l=x[2]-x[1];
	if(l>d){
		cout<<0<<"\n";
		return;
	}
	len=d/l;
	if(len==1) cout<<"0\n";
	else if(n<len*2) cout<<"0\n";
	else cout<<n-len*2+1<<"\n";
	return;
}
void solve(){
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	ans=0;
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j && abs(x[i]-x[j])<=d){
				dis[i][j]=1;
				cnt[i][j]++;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==k || j==k) continue;
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					cnt[i][j]=cnt[i][k]*cnt[k][j];
				}
				else if(dis[i][k]+dis[k][j]==dis[i][j]){
					cnt[i][j]++;
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2) ans++;
//			cout<<cnt[i][j]<<" ";
		}
//		cout<<"\n";
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		
		if(11<=c && c<=12){
			solveA();
		}
		else{
			solve();
		}
		
		//solveA();
	}
	return 0;
}
