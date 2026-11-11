#include<bits/stdc++.h>
using namespace std;
string s,z;
long long n,a,p;
string x,y;
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>z;
		for(int j=0;j<a;j++){
			s+=z;
		}
	}
	//read s
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			p=1;ans++;
		}
		
	}
	if(p==0){
		cout<<0;
		return 0;
	}
	
	cout<<ans;
	return 0;
}
