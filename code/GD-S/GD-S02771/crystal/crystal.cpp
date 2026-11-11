#include <bits/stdc++.h>
using namespace std;
long long a[60005],n,m,_max,k,s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(long long i=1;i<n;i++){
		k=0;
		s=1;
		for(long long j=i-1;j>=0;j--){
			if(a[i]-a[j]+k>m)break;
			k+=a[i]-a[j];
			s++;
		}
		if(s>_max)_max=s;
	}
	cout<<_max;
	return 0;
} 
