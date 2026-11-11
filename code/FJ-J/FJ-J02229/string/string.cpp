#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200002];
char b[200002];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		
	}
	long long ans=0;
	for(int i=1;i<=n/2;i++){
		if(b[i]!=b[n-i+1]){
			ans+=max(a[i],a[n-i+1]);
			if(a[i]>a[n-i+1])a[n-i]-=a[i]-a[n-i+1];
			else a[i+1]-=a[n-i+1]-a[i];
		}
	}
	cout<<ans;
	return 0;
}
