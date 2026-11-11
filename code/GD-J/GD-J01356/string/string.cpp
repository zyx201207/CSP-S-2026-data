#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int m;
	string s;
	string x;
	string c;
	for(int i=1;i<=n;i++){
		cin>>m;
		cin>>s[i];
		x[i]+=s[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]==s[i+1]){
			cout<<"0";
			return 0;
		}
	}
	int a=1;
	for(int i=n;i>=1;i--){
		c[a]+=x[i];
		a++;
	} 
	int b=0;
	for(int i=1;i<=n;i++){
		if(c[i]==x[i]){
			b++;
		}
	} 
	return 0;
} 
