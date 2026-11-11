#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	int n;
	cin >> n;
	if(n<=1){
		cout<<0;
		return 0;
	}
	int l[n]={0};
	char s[n]={0};
	for(int a=0;a<n;a=a+1){
		cin >> l[a];
		cin >> s[a];
	}
	if(n<=2){
		if(s[0]==s[1]){
			cout<<0;
			return 0;
		}else if(l[0]>l[1]){
			cout<<l[1];
		}else if(l[1]>l[0]){
			cout<<l[0];
		}else if(l[1]==l[0]){
			cout<<l[1];
		}
		}
	}

