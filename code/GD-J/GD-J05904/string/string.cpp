#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	char x;
	int a=0,l=0,sum=0;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>l;
		cin>>x;
		for(int j=0;j<l;j++){
			s+=x;
		}
	}
	for(int k=s.size()-1;k>(s.size()-1)/2;k--){
		int xiab=0;
		if(s[k]==s[xiab]) continue;
		if(s[k]!=s[xiab]){
			s[k]=s[xiab];
			sum++;
		}
		xiab++;
	}
	cout<<sum;
	return 0;
}

