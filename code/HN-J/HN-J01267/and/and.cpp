#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20005;
long long c[N][N];
long long n,m;
long long a[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[i][j]=a[i] and a[j];
		} 
	}
	int sum=0;
	for(int z=1;z<=m;z++){
		int maxn=-20005;
		int ma1,ma2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(c[i][j]>maxn){
					maxn=c[i][j];
					ma1=i;
					ma2=j;
				}
			}
		}
		c[ma1][ma2]=0;	
		sum=sum and maxn;	
	}
	cout<<sum;

	return 0;
}

