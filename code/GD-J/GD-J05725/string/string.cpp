#include <bits/stdc++.h>
using namespace std;
long long n,a[100000005],sum,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
	}
	for(int i=0;i<=n/2;i++){
		if(s[i]!=s[sum+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
