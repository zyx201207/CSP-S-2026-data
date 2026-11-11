#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char s[10000000];
	int n,k=0,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s[k]=c;
			k+=1;
		}
	}
	char m[1000000],o[1000000];
	for(int i=0;i<k/2;i++){
		m[i]=s[i];
		o[i]=s[k-i-1];
	}
	for(int i=0;i<k/2;i++){
		if(m[i]!=o[i]){
			sum+=1;
		}
	}
	cout<<sum;
	return 0;
} 
