#include<bits/stdc++.h>
using namespace std;
struct sNode{
	long long a;
	int b[35];
	bool c;
}x[200005];
long long n,m,h,vis[35],sum,ans,k[31]={536870912,268435456,134217728,67108864,33554432,16777216,8388608,4194304,2097152,1048576,524288,262144,131072,65536,32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1};
void poop(int y){
	h=x[y].a;
	for(int i=30;i>=1;i--){
		x[y].b[i]=h%2;
		h/=2;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i].a;
		x[i].c=1;
		poop(i);
	}
	for(int i=1;i<=30;i++){
		for(int j=1;j<=n;j++){
			vis[i]+=x[j].b[i];
		} 
	}
	for(int i=1;i<=31;i++){
		if(vis[i]<m){
			continue;
		}
		sum=0;
		for(int j=1;j<=n;j++){
			if(x[j].c==0){
				continue;
			}
			if(x[j].b[i]==0){
				x[j].c=0;
			}else{
				sum++;
			}
		}
		if(sum>=m){
			ans+=k[i-1];
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
} 
