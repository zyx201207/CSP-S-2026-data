#include <bits/stdc++.h>
using namespace std;

long long n,a[200005],sum;
char c[200005];
string s1,s2;

int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=a[i];j++){
			s1+=c[i];
		}
	}
	for (int i=n;i>=0;i--){
		for (int j=1;j<=a[i];j++){
			s2+=c[i];
		}
	}
	for (int i=0;i<n;i++){
		if (s1[i]!=s2[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
