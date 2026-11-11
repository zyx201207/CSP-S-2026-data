#include<bits/stdc++.h>
using namespace std;
long long n,m,max1=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stout);
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);if(a[0]==a[n-1]){cout<<n;return 0;}
	for(int i=n-1;i>=0;i--){
		long long cnt=1,m1=m;
		for(int j=i-1;j>=0;j--){
			if(m1>=a[i]-a[j]){m1-=(a[i]-a[j]);cnt+=1;
			}else break;
		}max1=max(max1,cnt);
		if(max1==n)break;
	}cout<<max1;
	return 0;
}
