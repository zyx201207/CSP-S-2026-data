#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const long long base=1;
long long a[N];
int w[N][35];
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		for(int j=0;j<=30;j++){
			if(a[i]&(base<<j))w[i][j]=1;
		}
	}
	long long ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if(w[j][i])cnt++;
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(!w[j][i])vis[j]=1;
			}
			ans+=(base<<i);
		}
	}
	printf("%lld",ans);
	return 0;
} 
/*
1 1
2

10 10
245 26424 2643 42 23462 132 1241512 13125 13 0

*/
