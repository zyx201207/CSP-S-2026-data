#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
string s;
int a[N];
char c[N];
int huiwen(string x){
	int sum=0;
	string y="";
	for(int i=x.size()-1;i>=0;i--){
		y+=x[i];
	}
	for(int i=0;i<x.size();i++){
		if(y[i]!=x[i]) sum++;
	}
	return sum/2;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		string k="";
		for(int j=1;j<=a[i];j++)k+=c[i];
		s+=k;
	}
	cout<<huiwen(s);
	return 0;
} 
