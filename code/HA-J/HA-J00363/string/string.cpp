#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("strint.out","w",stdout);
	int n;
	cin >>n;
	int c=0;
	string s;
	for(int i=1;i<=n;i++){
		int a;string b;
		cin >>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
		c+=a;
	}
	int d=c;
	d/=2;
	int f=1;
	for(int i=0;i<=d;i++){
		for(int j=c;j>=d;j--){
			if(s[i]==s[j]){
				f=0;
			}
			else if(f==1){
				break;
			}
			else {
				f=1;
			}
		}}
	if(f==0){
		cout<<f;
	}
	else {
		cout<<d;
	}
	return 0;
} 
