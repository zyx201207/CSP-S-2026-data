#include<bits/stdc++.h>
using namespace std;
int n,k=1,sum;
string s; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int o=k;o<k+a;o++){
			s[o]=b;
		}
		k+=a;
	}
	for(int i=1;i<=(k-1)/2;i++){
		if(s[i]!=s[k-i+1]){
			sum++;
			s[k-i+1]=s[i];
		}
	}
	for(int i=1;i<=k;i++){
		cout<<s[i];
	}
	cout<<sum;
	return 0;
} 

