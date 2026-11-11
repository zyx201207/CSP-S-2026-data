#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a=0,k=0,p=0,i=0,lop,js=0,c;
	string s,m;
	char b;
	cin>>n;
	while(n--){
		cin>>lop;
		a+=lop;
		cin>>b;
		for(;i<a;i++){
			s[i]=b;
			js++;
		}
	}
	k=js-1;
	if(js%2!=0){
	c=js/2+1;
	}
	else{
	c=js/2;
	}	
	for(int i=0;i<c;i++){
		if(s[i]!=s[k]){
			p++;
		}
		k--;
	}
	cout<<p;
	return 0;
}
