#include <bits/stdc++.h>
using namespace std;
string m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	long long siz=0,ans=0;
	for(int i=0;i<n;i++){
		long long inN;char inC;cin>>inN>>inC;
		for(int i=0;i<inN;i++){
			m+=inC;
			siz++;
		}
	}for(int i=0;i<siz/2;i++){
		if(m[i]!=m[siz-i-1]){
			ans++;
		}
	}cout<<ans;
	return 0;
} 
