#include<bits/stdc++.h>
using namespace std;
int n;
int x[200010];
string a[200010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>x[i]>>a[i];
	}
	int j=n;
	long long ans=0;
	for(int i=1; i<=j; i) {
		if(x[i]>x[j]) {
			if(a[i][0]!=a[j][0])ans+=x[j];
			x[i]-=x[j];
			j--;
		} else if(x[i]==x[j]) {
			if(a[i][0]!=a[j][0]) {
				ans+=x[j];
			}
			i++;
			j--;
		} else {
			if(a[i][0]!=a[j][0])ans+=x[i];
			x[j]-=x[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
}
