#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
long long n,a[N],ans,cnt;
char c[N];
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i]>>c[i];
	int i=1;
	int j=n;
	while(1) {
		if(j==n/2) {
			cout<<ans*2;
			return 0;
		}
		if(c[j]!=c[i]) {
			ans+=min(a[j],a[i]);
			if(a[j]>a[i]) {
				a[j]-=a[i];
				i++;
			} else if(a[j]<a[i]) {
				a[i]-=a[j];
				j--;
			} else if(a[i]==a[j]){
				i++;
				j--;
			}
		}else if(c[j]==c[i]) {
			if(a[j]>a[i]) {
				a[j]-=a[i];
				i++;
			} else if(a[j]<a[i]) {
				a[i]-=a[j];
				j--;
			} else if(a[j]==a[i]){
				i++;
				j--;
			}
		}
	}
	return 0;
}

