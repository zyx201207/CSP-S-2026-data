#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,num=1,maxnum=0,a1,a2;
	long long a[10^12+5];
	cin>>n>>m;
	a2=m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		num=1;
		a1=a[i];
		for(long long j=1;j<=n;j++){
			if(j==i) continue;
			if(a[j]==a1) num++;
			else if(a[j]<a1){
				if(m>a[j]){
					m=m-(a[i]-a[j]);
					num++;
				}
				else if(m==a[j]){
					num++;
					m=0;
				}
				else continue;
			}
			else continue;
		}
		m=a2;
		maxnum=max(maxnum,num);
	}
	cout<<maxnum;
	return 0;
}
