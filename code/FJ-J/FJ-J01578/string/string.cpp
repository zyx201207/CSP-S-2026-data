#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
char c[N];
string s;
long long int sum=0,ans=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1) {
		cout<<0;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<sum;i++){
		if(s[i]!=s[sum-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

