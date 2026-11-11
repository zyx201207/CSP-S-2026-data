#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],k,cnt,z,zz,c[10000005],d[10000005];;
long long xf(long long aa,long long bb){//³Ë·½ 
	int cc=aa*aa;
	for(long long i=3;i<=bb;i++){
		cc*=aa;
	}
	return cc;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cnt++;
	}
	sort(a+1,a+n+1);
	long long j=1;
	for(long long i=cnt-m+1;i<=cnt;i++){
		b[j]=a[i];
		j++;
	}
	cnt=1;
	for(int i=1;i<=m-1;i++){
		z=0;
		zz=0;
		for(long long j=1;b[cnt]>0;j++){
			c[j]=b[cnt]%2;
			b[cnt]/=2;
			z++;
		}
		cnt++;
		for(long long j=0;b[cnt]>0;j++){
			c[j]=b[cnt]%2;
			b[cnt]/=2;
			zz++;
		}
		cnt++;
		z=max(z,zz);
		for(long long j=0;j<z;j++){
			if(c[i]==1&&d[i]==1) c[i]==1;
			else c[i]==0;
		}
	}
	for(long long i=0;i<z;i++){
		k+=(xf(2,i)*c[i]);
	}
	cout<<k;
	return 0;
} 
