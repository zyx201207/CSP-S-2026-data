#include<bits/stdc++.h>
using namespace std;
long long n,m,ma,wei,b[200010][40],a[200010][40],k[40]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
void fen(long l,long x){
	long long ans=1;
	while(x>k[ans]){ans++;}
	ma=max(ma,ans);
	while(x>0){
		if(x-k[ans]>=0) a[l][ans]=1,x-=k[ans];
		ans--;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){ 
		int x;
		cin>>x;
		fen(i,x);
	}
	for(int i=ma;i>=1;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]) sum++;
		}
		if(sum>=m){
			for(int k=1;k<=n;k++){
				if(!a[k][i]){
					for(int l=1;l<=m;l++) a[k][l]=0;
				}
			}
			wei+=k[i];
		}
	}
	cout<<wei;
	return 0;
}
