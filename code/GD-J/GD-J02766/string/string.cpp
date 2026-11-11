#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long q,n[200000],x,b=0,y=0,l=1,k=1;
	char m[200000];
	cin>>q;
	for(long long i=1;i<=q;i++){
		cin>>n[i]>>m[i];
		y+=n[i];
		for(long long j=1;j<=n[i];j++){
			s+=m[i];
		}
	}
	x=y/2;
	if(n[l]-n[q]>=0){
		if(m[k]!=m[q]){
			b+=n[q];
		}
	}else{
		if(m[k]!=m[q]){
			b+=n[l];
		}	
	}
	for(long long i=n[1];i<x;i++){	
		if(s[i]!=s[y-i+1]){
			b++;
		}	
	}
	cout<<b;
	return 0;
}
