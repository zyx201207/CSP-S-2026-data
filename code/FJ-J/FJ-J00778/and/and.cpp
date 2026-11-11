#include<bits/stdc++.h>
using namespace std;
int m,n,a[200000],cf[30]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=29;i>=0;i--){
		int g=0;
		for(int j=0;j<n;j++){
			if((a[j]>>(i-1))&1){
				g++;
			}
			else{
				break;
			}
		}
		if(g>=m){
			n=g;
		}
		else{
			for(int j=0;j<n;j++){
				if((a[j]>>(i-1))&1){
					a[j]-=cf[i-1];
				}
			}
			sort(a,a+n,cmp);
		}
		if(n==m){
			break;
		}
	}
	int s=a[0];
	for(int i=1;i<n;i++){
		s&=a[i];
	}
	cout<<s;
	return 0;
}
