#include<bits/stdc++.h>
using namespace std;
int cnt[301][301]; long long d,x[2000001],n;
int dis[301][301];
void s1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			cnt[i][j]=0;
			if(x[j]-x[i]<=d){
				dis[i][j]=1;
			}else{
				dis[i][j]=1000;
			}
		}
	}
	for(int i=2;i<n;i++){
		for(int u=1;u<i;u++){
			for(int v=i+1;v<=n;v++){
				if(dis[u][i]+dis[i][v]<dis[u][v]){
					dis[u][v]=dis[u][i]+dis[i][v];
					cnt[u][v]=1;
				}else if(dis[u][i]+dis[i][v]==dis[u][v]){
					cnt[u][v]++;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}

void s2(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	long long k=x[2]-x[1];
	long long p=d/k;
	if(p<=1)
		cout<<0<<endl;
	else
		cout<<n-p<<endl;
}

void s3(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	long long ans=n*(n-1)/2;
	for(int i=1;i<n;i++){
		for(int j=2;j<=n;j++){
			if(x[j]-x[i]<=d)
				ans--;
		}
	}
	cout<<ans<<endl;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c; cin>>c;
	int T; cin>>T;
	
	if(c<=6){
		while(T--){
			s1();
		}
	}
	
	if(c==11||c==12){
		while(T--){
			s2();
		}
	}
	
	if(c==13||c==14){
		while(T--){
			s3();
		}
	}
	return 0;
}
