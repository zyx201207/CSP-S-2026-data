#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main(){
	long long n,l=0,s=0,b=1;
	cin >>n;
	long long a[n+1];
	char c[n+1];
	char s1[n+1];
	for(int i=1;i<=n;i++){
		cin >>a[i]>>c[i];
		if(n==1){
			cout <<0;
			return 0;
		}
		for(int j=1;j<=a[i];j++){
			s1[b]=c[i];
			b++;
		}
		l+=a[i];
	}for(int i=1;i<=n;i++){
		
	}
	for(int i=1;i<=l;i++){
		if(s1[i]!=s1[l+1-i]){
			s1[i]=s1[l+1-i];
			s++;
		}
	}cout <<s;
	return 0;
}
