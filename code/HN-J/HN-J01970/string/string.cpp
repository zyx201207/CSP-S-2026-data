#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
string s;
int cnt=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int a;
		char b;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			s+=b;
		}
		k+=a;
	}
	int k2=k/2;
	string s1,s2;
	for(int i=0;i<k2;i++){
		s1+=s[i];
	}
	for(int i=k-1;i>k2;i--){
		s2+=s[i];
	}
	for(int i=0;i<=k2;i++){
		if(s1[i]!=s2[i]){
		cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
