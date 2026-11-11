#include<bits/stdc++.h>
using namespace std;
string x;
long long n=0;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int z;
		cin>>z;
		char a;
		cin>>a;
		for(int i=1;i<=z;i++){
			x+=a;
		}
		n+=z;
	}
	int s=0,maxl;
	for(int i=1;i<=n/2;i++){
		if(x[i-1]!=x[n-i]){
			s++;
		}
	}
	maxl=s;s=0;
	cout<<maxl;
	return 0;
}


