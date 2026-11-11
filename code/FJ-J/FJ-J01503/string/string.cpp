#include<bits/stdc++.h>
using namespace std;
int n,a,q=0;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		while(a--) s+=c;
	}
	int x=s.size()/2;
	if(s.size()%2==1) x++;
	for(int i=0,j=s.size()-1;i<x;i++,j=s.size()-i-1){
		if(s[i]!=s[j]){
			q++;
		}
	}
	cout<<q;
	return 0;
}
