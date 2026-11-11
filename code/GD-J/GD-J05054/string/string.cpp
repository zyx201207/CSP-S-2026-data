#include <bits/stdc++.h>
using namespace std;
long long n,r=0,q,sum=0;
string s,ss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;	
	for(int i=0;i<n;i++){
		long long m;
		char e;		
		cin>>m>>e;
		for(int i=r;i<m+r;i++){			
			s[i]=e;					
		}
		r+=m;
	}
	if(r%2==0){
		q=r/2;
	}else{
		q=r/2+1;
	}
	for(int i=0;i<r;i++){
		ss[i]=s[i];
	}
	for(int i=q;i<r;i++){
		ss[i]=ss[r-i-1];
	}
	for(int i=0;i<r;i++){
		if(s[i]!=ss[i]){
			sum++;	
		}
	}
	cout<<sum;
	return 0;
} 
