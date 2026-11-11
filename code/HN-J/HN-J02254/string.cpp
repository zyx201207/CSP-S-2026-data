#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen(string.in,"r",strin);
	//freopen(string.out,"w",stdout);
	int n;
	long long a,h=0,k=0;
	char c;
	string s="";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		h+=a;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	for(long long i=0;i<h/2;i++){
		if(s[i]!=s[s.size()-i-1]) k++;
	}
	cout<<k;
}
