#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long sum;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<=n/2;i++){
		if(c[i]!=c[n-i+1]){
			sum+=a[i];
			a[n-i]-=a[i]-a[n-i+1];
		}
		if(a[i]>a[n-i+1]&&c[i]==c[n-i+1]){
			sum+=a[i]-a[n-i+1];
			a[n-i]-=a[i]-a[n-i+1];
		}
	}
	cout<<sum;
	return 0;
}
