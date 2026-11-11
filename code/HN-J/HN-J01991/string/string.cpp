#include<bits/stdc++.h>
using namespace std;
vector<char> s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,i,j,a,l=0,ll=0;
	char c;
	cin>>n;
	s.push_back('0');
	for(i=1;i<=n;i++){
		cin>>a>>c;
		l+=a;
		for(j=1;j<=a;j++){
			s.push_back(c);
		}
	}
	if(l%2==0){
		for(i=1;i<=l/2;i++){
			if(s[i]==s[l+1-i]) ll++;
		}
	}
	else{
		for(i=1;i<=l/2+1;i++){
			if(s[i]!=s[l+1-i]) ll++;
		}
	}	
	cout<<ll;
	return 0;
} 
