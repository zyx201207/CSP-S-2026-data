#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	string s;
	char b[200005];
	int a[200005];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++){
			s+=b[i]; 
	}
		
	}
	for(int i=0;i<s.size();i++){
		
		if(s[i]!=s[s.size()-i-1]){
			cnt+=1;
		}
		
	}
	cout<<cnt/2;
	
	
	return 0;
} 
