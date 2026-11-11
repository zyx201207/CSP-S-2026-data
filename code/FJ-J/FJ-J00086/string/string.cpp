#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[n+1];
	long long ans=0,d=1,l=n;
	char b[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(d<=l){
		if(b[d]!=b[l]){
			if(a[d]>=a[l]){
				ans+=a[l];
			}
			else{
				ans+=a[d];
			}
		}int e=a[d];
		a[d]-=a[l];
		a[l]-=e;
		if(a[d]<=0)d++;
		if(a[l]<=0)l--;
	}
	cout<<ans;
	return 0;
}
