#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200005];
string s;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long k=n;
	long long i=1;
	while(n--){
		cin>>a[i]>>c[i];
		i++;
	}
	long long j=1;
	while(j<k){
		if (c[j]!=c[k]&&a[j]==a[k]){
			ans+=a[j];
			k--;
			j++;
			continue;
		}
		if (c[j]!=c[k]&&a[j]<a[k]){
			ans+=a[j];
			a[k]-=a[j];
			j++;
			continue;
		}
		if (c[j]!=c[k]&&a[j]>a[k]){
			ans+=a[k];
			a[j]-=a[k];
			k--;
			continue;
		}
	}
	cout<<ans;
	return 0;
}
