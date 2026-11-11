#include<bits/stdc++.h>
using namespace std;
typedef long long LLD;
const int _S=5e5+1;
int n;
long long a[_S],b[_S],c[_S],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int xh=1;xh<=n;xh++){
		scanf("%lld",a+xh);
		b[xh]=a[xh]-a[xh-1];
	}
	bool bj=0;
	for(int i=2;i<=n;i++)
		if(a[i]<a[i-1]){
			bj=1;
			break;
		}
	if(bj) sort(a+1,a+1+n);
	for(int xh=2;xh<=n;xh++){
		c[xh]=c[xh-1]+(xh-1)*(a[xh]-a[xh-1]);//c[xh]表示 合并由第1到第xh颗所需要增加的能量值 
	}
	int l=1,lgh=1,maxn=0;
	do{
		for(int i=l+lgh;i<=n;i++){
			long long ned=c[i]-c[l]-(l-1)*(a[i]-a[l]);
			if(ned<=m){
				lgh=max(lgh,i-l+1);
				continue;
			}
			else break;
		}
		if(l==n-1)break;
		l++;
	}while(1);
	printf("%d",lgh);
	return 0;
}
