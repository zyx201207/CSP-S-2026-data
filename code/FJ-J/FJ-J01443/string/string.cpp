#include<bits/stdc++.h>
using namespace std;
int n,k;
char b;
string a;
int check(string x){
	int sum=0;
	for(int i=0;i<x.size()/2;i++){
		if(x[i]!=x[x.size()-i-1]) sum++;
	}return sum;
}int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k>>b;
		for(int j=0;j<k;j++){
			a+=b;
		}
	}cout<<check(a);
	return 0;
}
