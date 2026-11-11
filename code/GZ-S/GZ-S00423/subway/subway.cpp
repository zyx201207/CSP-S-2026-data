//GZ-S00423 ¿ÓΩ®¿§
#include <bits/stdc++.h>
using namespace std;
const int N=114514;
#define ll long long;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,a[N];
	for (int i=1;i<=m;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		int k,b[N]={0},c[N]={0};
		cin>>k;
		cin>>b[i]>>c[i];
	}
	for (int ii=0;ii<q;ii++){
		int st,ed,num=0,kl=0,lk=0;
		cin>>st>>ed;
		num=a[st]+a[ed];
		cout<<num<<endl;
	}
	return 0;
} 
