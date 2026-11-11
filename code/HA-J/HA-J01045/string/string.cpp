#include<bits/stdc++.h>

using namespace std;
long long a[3000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	int n,sum=0;
	string s[5000];
	char r;
	cin>>n;
	if(n<=1){
		cout<<0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>r;
		for(int j=0;j<a[i];j++){
			s[j]=r;
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]!=s[n-i-1])sum++;
	}
	cout<<sum;
	
     


return 0;	
} 

