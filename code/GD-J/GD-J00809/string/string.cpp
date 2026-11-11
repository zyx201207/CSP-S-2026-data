#include<bits/stdc++.h>
using namespace std;
long long k;
int n;
int a;
char c;
string s;
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	} 
	int l=s.size();
	s=" "+s; 
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
