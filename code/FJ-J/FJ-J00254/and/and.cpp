#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,t[35],l=1;
int f[35]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=0;f[j]<=a[i]&&j<=30;j++){
			t[j]=t[j]+(a[i]&f[j])/f[j];
		}
	}
	for(int i=30;i>=0;i--){
		if(t[i]>=m){
			for(int j=1;j<=n;j++){
				if(a[j]!=-1){
					a[j]=a[j]%f[i];
					if(a[j]<f[i-1]){
						for(int k=0;f[k]<=a[j]&&k<=30;k++){
							t[k]=t[k]-(a[j]&f[k])/f[k];
						}
						a[j]=-1;
					}
				}
			}
			ans=ans+f[i];
		}
	}
	cout<<ans;
	return 0;
}
