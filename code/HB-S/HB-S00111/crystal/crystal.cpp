#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long sum=0,len=0;
	for(int i=1;i<=n;i++){
		if(sum>m) break;
		if(sum+i<=m){
			sum+=i;
			len++;
		}
	}
	while(a[len+1]!=a[len]&&len+1>n){
		len++;
	}
	cout<<len+1;
	return 0;
}
