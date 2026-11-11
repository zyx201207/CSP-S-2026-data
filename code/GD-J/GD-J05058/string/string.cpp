#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,cnt;
char b[200005];
string s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		cnt+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)
			s+=b[i];
	} 
	for(int i=1;i<=cnt;i++){
		if(s[i]!=s[1+n-i])ans++;
	}
	cout<<ans;
	return 0;
}
