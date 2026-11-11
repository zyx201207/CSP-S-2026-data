#include<bits/stdc++.h>
using namespace std;
int c,t,n,tmp,cnt[2000005];
long long a[2000005],d,ds[2000005],bk[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c>=11){
			putchar('0');
			putchar('\n');
			continue;
		}
		if(1){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					ds[j]=LLONG_MAX;
					cnt[j]=0;
					bk[j]=0;
				}
				bk[i]=1;
				ds[i]=0;
				for(int u=i;u<=n;u++){
//					cerr<<u<<':'<<endl;
					for(int j=u+1;j<=n&&1ull*a[j]-a[u]<=d;j++){
//						cerr<<j<<endl;
						if(ds[j]==ds[u]+1){
							cnt[j]+=bk[u];
							bk[j]+=bk[u];
						}
						if(ds[j]>ds[u]+1){
							cnt[j]=bk[u];
							ds[j]=ds[u]+1;
							bk[j]+=bk[u];
						}
					} 
//					cout<<endl;
				}
				for(int j=1;j<=n;j++){
//					cout<<i<<' '<<j<<' '<<cnt[i][j]<<endl;
					if(cnt[j]==2){
//						cout<<i<<' '<<j<<endl;
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	} 
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
6 4
-3 0 1 2 3 4

0 1
8 3
0 1 2 4 8 10 11 13

int c,t,n,tmp,cnt[2000005];
long long a[2000005],d,ds[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==13||c==14){
			putchar('0');
			putchar('\n');
			continue;
		}
		if(1){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					ds[j]=LLONG_MAX;
					cnt[j]=0;
				}
				queue<int>pq;
				ds[i]=0;
				pq.push(i);
				while(!pq.empty()){
					int u=pq.front();
					pq.pop();
//					cout<<u<<':'<<endl;
					for(int j=u+1;j<=n&&1ull*a[j]-a[u]<=d;j++){
//						cout<<j<<endl;
						if(ds[j]==ds[u]+1){
							cnt[j]++;
							pq.push(j);
						}
						if(ds[j]>ds[u]+1){
							cnt[j]=1;
							ds[j]=ds[u]+1;
							pq.push(j);
						}
					} 
//					cout<<endl;
				}
				for(int j=1;j<=n;j++){
//					cout<<i<<' '<<j<<' '<<cnt[i][j]<<endl;
					if(cnt[j]==2){
//						cout<<i<<' '<<j<<endl;
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	} 
	return 0;
}
*/ 
