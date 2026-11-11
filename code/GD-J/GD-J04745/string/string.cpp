#include <bits/stdc++.h>
using namespace std;
int n,a[2000005],chang=0,shucmp;
long long cnt=0;
int s[5000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char cmp;
		cin>>shucmp>>cmp;
		chang+=shucmp;
		for(int i=0;i<=shucmp;i++){
			s[i]=cmp-'a';
		}	
		shucmp=0;
	}
	for(int i=0;i<chang/2;i++){
		if(s[i]!=s[chang-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
