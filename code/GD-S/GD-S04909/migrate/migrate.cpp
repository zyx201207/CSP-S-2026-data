#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans;
long long z[5005][5005];//i-j至少走几次 
long long a[2000005],d; 
int lj(int x,int y){
	int cnt=0;
	for(int i=x+1;i<y;i++){
		if(z[x][i]+z[i][y]==z[x][y])
		cnt++;
	}
	return cnt;
}
int dfs(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d) z[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int q=i+1;q<j;q++){
				if(z[i][q]!=0x3f3f3f3f&&z[q][j]!=0x3f3f3f3f)
				z[i][j]=min(z[i][q]+z[q][j],z[i][j]);
			}
		}
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]>d){
				if(lj(i,j)==2)
				ans++;
			}
		}
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		ans=0;
		memset(z,0x3f,sizeof(z));
		cout<<dfs()<<endl;
	}
	return 0;
}
