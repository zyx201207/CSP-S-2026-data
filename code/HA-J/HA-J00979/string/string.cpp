#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,l,da;
	char a;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>a;
		for(int j=1;j<=m;j++){
			s+=a;
			//cout<<s<<endl;
		}
		l+=m;
	}
	//cout<<l<<endl;
	if(n==1){
		cout<<0;
		return 0;	
	}
	if(l%2){
		da=0;
		for(int i=0;i<l/2;i++){
			if(s[i]!=s[l-i-1])da++;
		}
	}
	else {
		da=0;
		for(int i=0;i<l/2-1;i++){
			if(s[i]!=s[l-i-1])da++;
		}
		if(s[l/2-1]!=s[l/2])da++;
	}
	cout<<da;
	return 0;
} 
