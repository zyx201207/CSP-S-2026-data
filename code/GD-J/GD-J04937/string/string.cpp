#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b,d=0;
	cin>>a;
	char x;
	vector<char> xl;
	for(int i=0;i<a;i++){
		cin>>b>>x;
		d+=b;
	    for(int j=0;j<b;j++)xl.push_back(x);
	}
	int c=0;
	for(int i=0;i<d/2;i++)
	if(xl[i]==xl[d-i-1])c++;
	
	cout<<d/2-c;
	return 0;
}
