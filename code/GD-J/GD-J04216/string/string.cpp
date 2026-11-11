#include<bits/stdc++.h>
using namespace std;
long long n,a[300005],ans;
char c[300005];
string s;
int main(){
	/*freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);*/
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long o=1;
	for(long long i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[o++]=c[i];
		}
	}
	for(long long i=1;i<=(o/2);i++){
		if(s[i]!=s[o-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
