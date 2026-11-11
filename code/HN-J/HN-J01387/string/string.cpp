#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x=0;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		unsigned long long k;
		cin>>k;
		char a;
		cin>>a;
		for(int j=0;j<k;j++){
			s[x]==a;
			x++;
		}
		
	}
	unsigned long long y=0;
	if((x+1)%2==0){
		y=(x+1)/2;
	}else{
		y=(x+1)/2-1;
	}
	cout<<y;
	return 0;
} 
