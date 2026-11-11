#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200010];
char c[200010];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long cnt1=0;
	for(long long i=1;i<=n-cnt1;){
		if(a[i]>a[n-cnt1]){
			if(c[i]==c[n-cnt1]){
				a[i]-=a[n-cnt1];
				cnt1++;
			}
			if(c[i]!=c[n-cnt1]){
				ans+=a[n-cnt1];
				a[i]-=a[n-cnt1];
				cnt1++;
			}
		}
		if(a[i]<a[n-cnt1]){
			if(c[i]==c[n-cnt1]){
				a[n-cnt1]-=a[i];
				i++;
			}
			if(c[i]!=c[n-cnt1]){
				ans+=a[i];
				a[n-cnt1]-=a[i];
				i++;
			}
		}
		if(a[i]==a[n-cnt1]){
			if(c[i]!=c[n-cnt1]){
				ans+=a[n-cnt1];
				i++;
				cnt1++;
			}
			if(c[i]==c[n-cnt1]){
				cnt1++;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
