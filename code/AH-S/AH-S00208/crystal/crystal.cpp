#include<bits/stdc++.h>
using namespace std;
long long m,a[500010],sum1,sum2,Max;
long long d=1,n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	while(m!=0&&a[1]!=a[n]){
		if(a[d]==a[d+1]){
			d++;
		}else if(a[d]<a[d+1]){
			for(long long i=1;i<=d;i=i){
				if(m!=0){
					a[i]++;
					m--;
				}
				if(m==0){
					Max=a[i];
					break;
				}
				i++;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		if(a[i]>Max)break;
		if(a[i]==Max)sum1++;
	}
	for(long long i=1;i<=n;i++){
		if(a[i]>Max)break;
		if(a[i]==Max-1)sum2++;
	}
	if(m!=0)cout<<n;
	else cout<<max(sum1,sum2);
	return 0;
}
