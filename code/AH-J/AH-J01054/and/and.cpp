#include <bits/stdc++.h>
using namespace std;
long long a[200010];
long long maxn=0;
long long zx[35];
long long maxnn=0;
bool cmp(long long x,long long y){
	long long xx=x;
	int w[35]={0},v[35]={0},r[35]={0};
	for(int i=31;i>=1;i--){
		if(x>=zx[i]){
			w[i]=1;
			x-=zx[i];
		}
	}
	for(int i=31;i>=1;i--){
		if(y>=zx[i]){
			v[i]=1;
			y-=zx[i];
		}
	}
	for(int i=1;i<=31;i++){
		if(v[i]==1&&w[i]==1){
			r[i]=1;
		}
	}
	long long cntn=0;
	for(int i=1;i<=31;i++){
		if(r[i]==1){
			cntn+=zx[i];
		}
	}
	maxnn=cntn;
	return xx<cntn;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long cnt=1;
	zx[1]=1;
	for(int i=2;i<=31;i++){
		zx[i]=cnt*2;
		cnt*=2;
	}
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=1;
	for(int i=1;i<=n;i++){
		long long sum=a[i];
		for(int j=i+1;j<=n;j++){
			if(k<m){
				if(cmp(sum,a[j])){
					sum=maxnn;
					k++;
				}
			}else{
				break;
			}
			
		}
		cout<<sum<<endl;
		maxn=max(maxn,sum);
	}
	cout<<maxn;
	return 0;
}
