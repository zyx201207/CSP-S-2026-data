#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],w[32],x[32][200005];
int e[32]={1,2,4,8,16,32,64,128
,256,512,1024,2048,4096,8192,16384
,32768,65536,131072,262144,524288
,1048576,2097152,4194304,8388608
,16777216,33554432,67108864,134217728
,268435456,536870912,1073741824};
int ans=1073741824;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int nn=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int p=a[i];
		for(int j=30;j>=0;j--){
			if(p>=e[j]){
				w[j]++;
				x[j][i]=1;
				p-=e[j];
			}
		}
	}
	long long num=0;
	for(int i=30;i>=0;i--){
		if(w[i]<m)continue;
		num+=e[i];
		for(int j=1;j<=n;j++){
			if(b[j]==1)continue;
			if(x[i][j]==0){
				b[j]=1;
				for(int u=i-1;u>=0;u--){
					w[u]-=x[u][j];
				}
			}
		}
	}
	cout<<num;
	return 0;
}
