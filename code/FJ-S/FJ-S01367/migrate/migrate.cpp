#include<bits/stdc++.h>
using namespace std;
long long _,T;
long long n,m;
long long a[2000005];
long long b[2000005];
long long c[2000005];
queue<pair<long long,long long> > q;
int main(){
	freopen("migrate.in","r",stdin);
//	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>_>>T;
	while(T--){
		cin>>n>>m;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		long long s,u,ans=0;
		for(long long i=1;i<=n;i++){
			q.push({i,0});c[i]=1;
			while(!q.empty()){
				u=q.front().first;s=q.front().second;q.pop();
				for(long long j=u+1;j<=n;j++){
					if (a[j]-a[u]>m) break;
					if (b[j]==0){
						b[j]=s+1;c[j]=c[u];
						q.push({j,s+1});
					}else if (b[j]==s+1)c[j]+=c[u];
				}
			}
			for(long long j=1;j<=n;j++){
				if (c[j]==2) ans++;
			}
//			cout<<i<<":\n";
//			for(long long j=1;j<=n;j++)cout<<b[j]<<' ';cout<<endl;
//			for(long long j=1;j<=n;j++)cout<<c[j]<<' ';cout<<endl;
			for(long long j=1;j<=n;j++){b[j]=0;c[j]=0;}
		}
		cout<<ans<<endl;
	} 
	return 0;
}
/*
7 666666666666666663
-1000000000000000000 
-555555555555555558
-111111111111111116
111111111111111105
333333333333333326
555555555555555547 
999999999999999989

1 1
7 5
1 6 10 11 14 15 19
*/
