#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
long long sum[500010];
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=a[1];i<=a[n-1];i++){
		int num=m;
		int j=0;
		int ansf=0;
	    while(num>=(i-a[j]) && i>=a[j]){
	    	ansf++;
	    	num=num-(i-a[j]);
	    	j++;
		}
		if(ansf>ans) ans=ansf;
	}
	cout<<ans;
	return 0;
}
