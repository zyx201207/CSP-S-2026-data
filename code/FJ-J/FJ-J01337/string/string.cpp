#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char b[200005];
long long ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
