#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,h=0,h1=0,cnt=0;
	int n;
	string w;
	string s[199999];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>w;
		h+=a; 
		for(int j=1;j<=a;j++){
			s[j]=w;
		}
	}
	if(h%2==0){
		h1=h/2;
		for(int i=1;i<=h1;i++){
			if(s[i]==s[h-i+1]){
				cnt++;
			}
		}
	}
	if(h%2==1){
		h1=h/2+1;
		for(int i=1;i<=h1;i++){
			if(s[i]!=s[h-i+1]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	
	
	return 0;
}
