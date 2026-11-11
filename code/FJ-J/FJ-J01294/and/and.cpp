#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,last;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int j=n-1;j>=n-m;j--){
		if(j==n-1){
		last=a[j];
			ans=0;
		}
		else{
			ans=(last&a[j]);
		}
	}
	cout<<ans;
	return 0;
}
