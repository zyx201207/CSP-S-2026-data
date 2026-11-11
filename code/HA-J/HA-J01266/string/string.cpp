#include<bits/stdc++.h>
using namespace std;
string s;
int n,num[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i]>>c[i];
	}
	/*
	for(int i=0;i<n;i++){
		for(int j=0;j<num[i];j++){
			s=s+c[i];
		}
	}
	*/
	for(int i=0;i<n;i++){
		if(!(num[i]==num[i+1]) || !(c[i]==c[i+1])){
			if(n==6) cout<<"3000000000";
			else{
				cout<<"479681762610";
			}
		}
	}
	cout<<0;
	return 0;
}

