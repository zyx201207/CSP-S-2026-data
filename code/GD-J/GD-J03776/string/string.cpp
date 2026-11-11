#include<bits/stdc++.h> 
using namespace std;
main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0;
	cin>>n;
	long long i=0,j=0;
	long long len=0,w=0;
	string all;
	while(i<n){
		long long a=0;
		string c;
		cin>>a>>c;
		j=0;
		while(j<a){
			all[w]=c[0];
		j++;
		w++;}
	i++;}
	
	long long wrong=0;
	i=1;
	while(i<=n/2){
		if(all[i]!=all[len-i+1])wrong++;
	i++;}
	
	cout<<wrong<<'\n';
	
	return 0;
}
