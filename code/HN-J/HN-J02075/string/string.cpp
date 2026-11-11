#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,s1;
	long long int n;
	long long int cnt=0,so=0;
	char a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cnt;
		cin>>a;
		for(int i=0;i<cnt;i++){
		    s+=a;
		}
	}
	int r=0;
	for(int i=s.size()-1;i>=0;i--){
		s1[r]=s[i];
		r++;
		
		
	}
	for(int i=0;i<s.size()/2;i++){
		if(s1[i]!=s[i]){
			s[i]=s1[i];
			so+=1;
		}
	}
	if(so==0){
		cout<<0;
	}else{
		cout<<so;
	}
	return 0;
}

