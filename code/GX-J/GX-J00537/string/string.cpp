#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c;
	string s;
	long long n,o,l=0,sum=0,k=0,b=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>o>>c;
		b+=o;
		for(int j=k;j<(o+k);j++){
			s[i]=c; 
		}
		k+=o;
	}
	if(b%2!=0){
	for(int i=b/2-1;i>=0;i--){
		l+=2;
		if(s[i]!=s[i+l]){
			s[i]=s[i+l];
			sum++;
		}
	}	
}else{
	l=-1;
	for(int i=b/2;i>0;i--){
		l+=2;
		if(s[i]!=s[i+l]){
			s[i]=s[i+l];
			sum++;
		}
		
	}	
}
	cout<<sum;
	return 0;
	}
