#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int n,l=0,ans=0;
	string m="",p="";
	cin>>n;
	
	long long a[n];
	char b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		l+=a[i];
		for(int j=0;j<a[i];j++){
			m+=b[i];
		}
	}
	if(n==1){
		cout<<'0';
		return 0;
	}
	for (int i=l-1;i>=0;i--){
		p+=m[i];
	}
	if(m==p){
		cout<<'0';
	}
	else{
		for(int i=0;i<l/2;i++){
			if(m[i]!=p[i]){
				ans++;
			}
		}
		cout<<ans;
	}
	
	return 0;
} 
