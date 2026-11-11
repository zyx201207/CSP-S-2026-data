#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];int n,m,ans;
int min(int x,int y){
	int k=1;
	for(int i=1;i<=y;i++){
		k*=x;
	}
	return k;
}
int biao[32]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648};
int yu(int x,int y){
	int shu=0;
	for(int uo=30;uo>=0;uo--){
		int po=biao[uo];
		int px,py;
		if(po<x) {
			x-=po;
			px=1;
		}
		if(po<y){
			y-=po;
			py=1;
		}
		if(px==py) shu+=po;
	}
	return shu;
}
bool dapa(){
	bool p=1;
	for(int i=1;i<=n;i++){
		if(a[i]%2==0){
			p=0;
		}
	}
	return p;
}
void dfs(int i,int sh,int dd){
	if(sh==0){
		ans=max(ans,dd);
	}
	for(int j=i+1;j<=n;j++){
		if((j+sh)<=n){
			dfs(j,sh-1,yu(dd,a[j]));
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int da=0;
		for(int i=1;i<=n;i++){
			da=max(da,a[i]);
		}
	}
	else if(m==2){
		int mmax=0,sum=0;
		for(int i=1;i<=m;i++){
			for(int j=i;j<=n;j++){
				mmax=max(mmax,yu(a[i],a[j]));
			}
		}
		cout<<mmax<<endl;
	}
	else if(dapa()){
		int uid=a[n];
		sort(a+1,a+1+n);
		for(int i=2;i<=m;i++){
			uid=yu(uid,a[n-i+1]);
		}
		cout<<uid<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			dfs(i+1,m-1,a[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}

