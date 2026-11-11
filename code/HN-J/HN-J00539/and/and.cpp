#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e3+7;
int a[MAXN];
long long g[MAXN][MAXN];
int jc[33]{1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
long long ans=0,pos=0;
int n,m;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	int maxx=0;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1){
			f=false;
		}
		maxx=max(a[i],maxx);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			g[i][j]=a[i]&a[j];
			pos=max(g[i][j],pos);
		}
	}
	if(m==2){
		cout<<pos;
		return 0;
	}
	if(f&&n>2000){
		bool f=false;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=31;j>=0;j--){
				if(a[i]==jc[j]-1){
					if(!f){
						f=true;
						ans=a[i];
					}
					else {
						ans=ans&a[i];
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(n>2000){
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	long long maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i==k||i==j||j==k) continue;
				maxn=max(g[i][j]&g[j][k],maxn);	
			}
		}
	}
	cout<<maxn;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
