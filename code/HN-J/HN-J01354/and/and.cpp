#include<bits/stdc++.h>
using namespace std;
int n,m,xb;
long long er[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
int a[200010];
int e[200010];
long long zuizhong[40];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	while(a[n]!=0){
		memset(e,0,sizeof(e));
		bool su=0;
		for(int i=n;i>n-m;i--){
			e[i]=a[i]%2;
			a[i]=a[i]/2;
		}
		for(int i=n;i>n-m;i--){
			if(e[i]!=1) {
				zuizhong[xb]=0;
				xb++;
				su=1;
				break;
			}
		}
		if(!su) zuizhong[xb]=1,xb++;
	}
	for(int i=0;i<=xb;i++){
		ans+=zuizhong[i]*er[i];
	}
	cout<<ans;
	return 0;
} 
