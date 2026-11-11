#include<bits/stdc++.h>
using namespace std;
long long n,t,cnt;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//aabbc -> aabaa
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>s1;
		for(int j=1;j<=t;j++){
			s+=s1;
		}
	}
	int i=0,j=s.size()-1;
	while(!(i==j||abs(i-j)==1)){
		if(s[i++]!=s[j--])cnt++;
	}
	cout<<cnt;
	return 0;
}
