#include<bits/stdc++.h>
using namespace std;

int qiuzhi(long long x){
	long long y=x;
	long long num=0;
	while(y/2!=0){
		if(y%2==1){
			num++;
		}
		y/=2;
	}
	return num+1;
}

struct lou{
	long long sum;
	long long b;
	int bianhao;
};
lou a[200001];

bool cmp(lou x,lou y){
	return x.sum>y.sum;
}
bool cmp2(lou x,lou y){
	return x.bianhao<y.bianhao;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum;
		a[i].b=qiuzhi(a[i].sum);
		a[i].bianhao=i;
	}
	sort(a+1,a+n+1,cmp);
	long long p=a[1].sum;
	for(int i=2;i<=m;i++){
		p=p & a[i].sum;
	}
	cout<<p;
	return 0;
}
