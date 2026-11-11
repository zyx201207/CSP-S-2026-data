#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[100005];
	long long ans=0;
	char b[100005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
		for(int i=0;i<=n;i++){
		if(n%2==1){
	    	if(i==n/2+1){
	    		break;
			}
		}
		if(b[n-i]!=b[i+1]){
			if(n-i-i-1==1){
			ans+=max(a[n-i],a[i+1])-(max(a[n-i],a[i+1])-min(a[n-i],a[i+1]));
			break;
		}
	    ans+=max(a[n-i],a[i+1]);
	    if(a[n-i]>a[i+1]){
	    	a[i+2]-=a[n-i]-a[i+1];
		}
		if(a[n-i]<=a[i+1]){
	    	a[n-i-1]-=a[i+1]-a[n-i];
		}
}
	}
	cout<<ans;
	return 0;
}
