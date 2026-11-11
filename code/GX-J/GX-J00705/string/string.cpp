#include <bits/stdc++.h>
using namespace std;
string s;
int n,x,k=0;
char ch;
int main (){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>ch;
		for(int j=0;j<x;j++){
			s+=ch;
		}
	}
	int t=s.size();
	if(t%2==0){
		int q=t/2;
		for(int i=0;i<q;i++){
			if(s[i]!=s[t-i]){
				k++;
			}
		}
	}else{
		int p=(t-1)/2;
		for(int i=0;i<p;i++){
			if(s[i]!=s[t-1-i]){
				k++;
			}
		}
	}
	cout<<k;
	return 0;
}

