#include<bits/stdc++.h>
using namespace std;

char z[10000005];

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	char b;
	int s,a,len=0,f=0,sum=0;
	cin >> s;
	for(int i=1;i<=s;i++){
		cin >> a;
		cin >> b;
		for(int j=1;j<=a;j++){
			z[j+len]=b;
		}
		len=len+a;
	}
	if(len%2==0){
		for(int i=1;i<=len/2;i++){
			if(z[i]!=z[len+1-i]){
				sum++;
			}
		}
		cout <<sum;
	}
	else{
		for(int i=1;i<=(len-1)/2;i++){
			if(z[i]!=z[len+1-i]){
				sum++;
			}
		}
		cout << sum;
	}
	return 0;
}
