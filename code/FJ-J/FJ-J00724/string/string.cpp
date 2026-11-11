#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","a",stdout); 
	long long a=0;
	string s="",c;
	long long m,n;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>n>>c;
		for(int j=0;j<n;j++){
			s+=c;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		int j=s.size()-1-i;
		if(s[i]!=s[j]){
			a++;
		}
	}
	cout<<a;
	
	return 0;
}
