#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x[10000001],cnt=0,m=0,sum[10000001],flag=1,nflag,l=1,r;
	char y[10000001];
	cin >> n;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		cin >> x[i]>>y[i];
		m+=x[i];
		sum[i]=sum[i-1]+x[i];
	}
	r=m;
	nflag=n;
	while(l<r){
		if(l>sum[flag]){
			flag++;
		}
		
		if(r<=sum[nflag-1]){
			nflag--;
		}
		if(y[nflag]!=y[flag]){
			cnt++;
		}
		l++;
		r--;
	}
	cout << cnt;
	return 0;
}
