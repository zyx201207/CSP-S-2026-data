#include<bits/stdc++.h>
using namespace std;
int x,s=0,n;
string t;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>c;
		for(int j=0;j<x;j++) t+=c;
	}
	int L=t.size();
	for(int i=0;i<L/2;i++){
		if(t[i]!=t[L-1-i]) s++;
	}
	cout<<s;
	return 0;
}
