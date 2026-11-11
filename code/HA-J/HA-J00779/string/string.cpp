#include<bits/stdc++.h>
using namespace std;
long long n,m,t,a,sum;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s1;
		for(int j=1;j<=a;j++){
			s+=s1;
		}
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
