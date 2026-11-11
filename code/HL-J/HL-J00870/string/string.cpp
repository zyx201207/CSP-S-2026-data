#include <bits/stdc++.h>
using namespace std;
const int N=2e5+100;
string c[N];
int n,a[N];
long long sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}long long mid=sum/2;
	int lr=0;
	sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(sum-a[i]<=mid&&sum>=mid)lr=i-1;
	}
	for(int i=1;i<=lr;i++){
		if(c[i]!=c[n-i+1]){
			if(a[i]<a[n-i+1]){
				ans+=a[i];
				if(c[i+1]!=c[n-i+1]){
					ans+=(a[n-i+1]-a[i]);
				}
				a[i+1]-=(a[n-i+1]-a[i]);
				a[i]=a[n-i+1];
			}else if(a[i]>a[n-i+1]){
				ans+=a[n-i+1];
				if(c[n-i]!=c[i]){
					ans+=(a[i]-a[n-i+1]);
				}
				a[n-i]-=(a[i]-a[n-i+1]);
				a[n-i+1]=a[i];
			}else{
				ans+=a[i];
			}
		}else{
			if(a[i]<a[n-i+1]){
				if(c[i+1]!=c[n-i+1]){
					ans+=(a[n-i+1]-a[i]);
				}
				a[i+1]-=(a[n-i+1]-a[i]);
				a[i]=a[n-i+1];
			}else if(a[i]>a[n-i+1]){
				if(c[n-i]!=c[i]){
					ans+=(a[i]-a[n-i+1]);
				}
				a[n-i]-=(a[i]-a[n-i+1]);
				a[n-i+1]=a[i];
			}
		}
	}cout<<ans;
	return 0;
}