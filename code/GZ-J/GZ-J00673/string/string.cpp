//GZ-J00673 遵义市第四初级中学 刘俊翔
#include<bits/stdc++.h>
using namespace std;

string hw(string s){
	string k;
	for(int i=s.size()-1;i>=0;i--){
		k+=s[i];
	}
	return k;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1];
	char b[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	string s;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=b[i];
		}
	}
	string k=hw(s);
	for(int i=0;i<s.size();i++){
		if(s[i]==k[i]){
			if(s[i+1]!=k[i+1]){
				cout<<s.size()-i-1;
			}
		}
	}
	cout<<0;
} 
