#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	/*-----*/
	long long n;
	cin>>n;
	long long a;
	string c;
	long long d=0,l=0;
	for(long long i=1;i<=n;i++){
		cin>>a;
		char m;
		cin>>m;
		for(int j=l+1;j<=l+1+a;j++){
			c[j]=m;
		}
		l+=a;
	}
	for(long long i=1;i<=l/2;i++){
		if(c[i]!=c[l+1-i]){
			d++;
		}
	}
	cout<<d;
	return 0;
	/*-----*/
	fclose(stdin);
	fclose(stdout);	
} 
