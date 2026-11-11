#include<iostream>
using namespace std;

int ishws(string a){
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-1-i]) return 0;
	}
	return 1;
}

int main(){
	long long int m,n,t=0;
	string b="";
	char c;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>n>>c;
		for(int j=1;j<=n;j++){
			b+=c;
		}
	}
	if(ishws(b)) cout<<0;
	else{
		for(int i=0;i<b.size()/2;i++){
			if(b[i]!=b[b.size()-1-i]) t++;
		}
		cout<<t;
	}
	return 0;
}
