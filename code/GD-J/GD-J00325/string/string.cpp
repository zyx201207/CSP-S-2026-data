#include<bits/stdc++.h>
using namespace std;
int n;
int a;
long long ans;
char b;
int l,t;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		l+=a;
		cin>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	int t=l%2==0?l/2+1:(l+1)/2;
	for(int i=1;i<t;i++){
		if(s[l-i]!=s[i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
