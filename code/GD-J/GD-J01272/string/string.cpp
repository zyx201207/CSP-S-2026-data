#include<iostream>
#include<string>
#include<cstdio>
using namespace std; 
long long a,n,r=1,k;
char c;
string s,q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=r;j<r+a;j++){
			s[j]=c;
		}
		r+=a;
	}r--;
	for(int i=1;i<=r;i++){
		q[i]=s[r-i+1];
	}
	
	k=r;
	for(int i=1;i<=r;i++){
		if(s[i]==q[i]){
			k--;
		}
	}
	cout<<k/2;
	return 0;
}
