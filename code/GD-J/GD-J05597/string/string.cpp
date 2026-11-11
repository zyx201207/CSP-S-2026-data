#include<bits/stdc++.h>
using namespace std;
const int a=1e6;
int n,q,r=0;
char s[a],w;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>q>>w;
		for(int j=0;j<q;j++){
			s[r]=w;
			r++;
		}
	}
	q=0;
	
	for(int i=0;i<r/2;i++){
		if (s[i]!=s[r-i-1]){
			q++;
			
		}
	}
	cout<<q;
	return 0;
} 
