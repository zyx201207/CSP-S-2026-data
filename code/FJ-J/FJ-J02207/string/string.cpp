#include <bits/stdc++.h>
using namespace std;
const int Q=2e5+10;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[Q],sum=0,k=0;
	vector<char> c[Q];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	vector<string> s[sum];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[i].push(c[i]);
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i]!=s[sum+1-i]) s[sum+1-i]=s[i]; k++;
	}
}
