//GZ-J00489 遵义市第四初级中学 游四鑫
#include<bits/stdc++.h>
using namespace std;
long long n,sum,ans;
string x="";
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		long long s;
		char a;
		cin>>s>>a;
		sum+=s;
		for(int j=1; j<=s; j++) {
			x+=a;
		}
	}
	for(int i=0; i<=sum/2; i++) {
		if(x[i]!=x[sum-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
