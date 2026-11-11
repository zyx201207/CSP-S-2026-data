#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	cin>>a;
	string k;
	long long h;
	string h1;
	for(int i=0;i<a;i++){
		cin>>h>>h1;
		for(int i=0;i<h;i++){
			k+=h1;
		}
	}
	unsigned long long cnt=0;
	for(int i=0;i<k.size()/2;i++){
		if(k[i]!=k[k.size()-1-i]){
			k[k.size()-1-i]=k[i];
			cnt++;
		}
	}
	cout<<cnt<<endl;
} 
