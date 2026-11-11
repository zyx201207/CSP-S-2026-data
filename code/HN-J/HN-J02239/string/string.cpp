#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,i,j,z=0;
	char c;
	string s;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>c;
		for(j=0;j<a;j++){
			s+=c;
		}
	}
	long long l=s.size();
	for(i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1])z+=1;
	}
	cout<<z; 
	return 0;
} 
