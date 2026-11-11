#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,sum=0;
	string s,b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s+=b[0];
		}
	}
	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0; 
}
