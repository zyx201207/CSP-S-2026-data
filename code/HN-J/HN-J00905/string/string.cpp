#include<bits/stdc++.h>
using namespace std;
vector<char> a;
char b;
bool s=0;
int n,l,o=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l>>b;
		for(int j=0;j<l;j++){
			a.push_back(b);
		}
	}
	int x=a.size();
	for(int i=0;i<x/2;i++){
		if(a[i]!=a[x-i-1]){
			o++;
		}
	}
	cout<<o;
	return 0;
}

