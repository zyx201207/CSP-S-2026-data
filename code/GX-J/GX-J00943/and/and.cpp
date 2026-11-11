#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],max1=INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)cin>>a[i];
	for(long long i=0;i<n;i++){
		for(long long j=i;j<n;j++){
			if((a[i]&a[j])>max1)max1=a[i]&a[j];
			}
	}
	cout<<max1;
	return 0;
	}
