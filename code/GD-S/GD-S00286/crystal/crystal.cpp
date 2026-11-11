#include<bits/stdc++.h>
using namespace std;
int n,pos=1;
long long m,a[500005],k=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	while(m>=0){
		m-=k*(a[pos+1]-a[pos]);
		k++;
		pos++;
	}cout<<pos-1;
	return 0;
}//全都不会
