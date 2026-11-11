#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[214514];
char c[214514];
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	for(int i=1; i<=n; i++) {
		cout<<a[i]<<" "<<c[i]<<endl; 
	}
	int i=1,j=n;
	while(1) {
		if(i>=j) break;
		if(c[i]!=c[j]) {
			if(a[i]<a[j]) {
				ans+=a[i];
				a[j]-=a[i];
				a[i]-=a[i];
				i++;
				continue;
			}
			else if(a[i]>a[j]) {
				ans+=a[j];
				a[i]-=a[j];
				a[j]-=a[j];
				j--;
				continue;
			}
			else {
				ans+=a[j];
				a[i]-=a[j];
				a[j]-=a[j];
				i++,j--;
				continue;
			}
		}
		else if(c[i]==c[j]) {
			if(a[i]<a[j]) {
				a[j]-=a[i];
				a[i]-=a[i];
				i++;
				continue;
			}
			else if(a[i]>a[j]){
				a[i]-=a[j];
				a[j]-=a[j];
				j--;
				continue;
			}
			else {
				a[i]-=a[j];
				a[j]-=a[j];
				i++,j--;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
