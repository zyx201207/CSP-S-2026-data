#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
int n,a;
char c;
string s=" ";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		} 
	}
	ull l=s.size()-1;
	ull cnt=0;
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l+1-i]){
			s[l+1-i]=s[i];
			cnt++;
		} 
	}
	cout<<cnt;
	return 0;
}

