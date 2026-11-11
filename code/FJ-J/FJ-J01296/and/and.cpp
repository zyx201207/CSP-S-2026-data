#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],p,maxn=-1,d[40]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,};
bool cmp(int x,int y){
	return x>y; 
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int l=m; 
	for(int i=0;i<=30;i++){
		if(d[i]>a[m]){
			p=i-1;
			break;
		}
	}
	for(int i=m+1;i<=n;i++){
		if(a[i]>d[p]){
			l++;
		}
	}
	int o=d[p+1]-1;
	int t=0;
	for(int i=1;i<=l;i++){
		b[i]=a[i]&o;
		if(b[i]==0){
			l++;
			t=1;
		}
		if(b[i]==d[p]&&t){
			l++;
			b[i]=0;
		}
	}
	sort(b+1,b+l+1,cmp);
	int maxn=b[1];
	for(int i=2;i<=m;i++){
		maxn=maxn&b[i]; 
	}
	cout<<maxn;
}
