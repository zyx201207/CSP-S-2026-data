#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum,ans;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		if(i>=1){
			if(b[i]==b[i-1])a[i-1]+=a[i],i--,n--;
		}
	}
	for(int l=0,r=n-1;l<=r;){
		if(b[l]!=b[r]){
			ans+=min(a[l],a[r]);	
		}if(a[l]<a[r])l++,a[r]-=a[l-1];
			else if(a[l]>a[r])r--,a[l]-=a[r+1];
			else l++,r--;
	}
	cout<<ans;
	return 0; 
} 

