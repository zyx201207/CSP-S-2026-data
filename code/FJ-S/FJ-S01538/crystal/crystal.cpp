#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500005],cnt,maxm = 1,shu,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		shu = a[i];
		cnt = 0;
		sum = 0;
		for(int j=0;j<i;j++){
			sum += a[j];
			cnt ++;
		}
		if((sum+m)*1.0/cnt >= shu){
			maxm = max(maxm,cnt+1);
		} 
	}
	 
	cout<<maxm;
	
	return 0;
} 
