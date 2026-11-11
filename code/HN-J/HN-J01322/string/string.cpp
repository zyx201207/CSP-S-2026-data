#include<bits/stdc++.h>
using namespace std;
long long a[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int d=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	if(n==1){
		cout<<0;
	}	
	for(int i=0;i<n;i++){
		if(s[i+1]==s[i]){
			d+=1;
		}
	}
	if(d!=0){
		cout<<0;
		return 0;
	}
	long long c=a[0];
	int b=0;
	for(int i=0;i<n;i+=2){
		if(s[i]==s[i+1]){
			c+=a[i+1];
			b+=1;
		}
	}
	long long sum=0;
	for(int i=n-1;i>n-b;i--){
		sum+=a[i];
	}
	if(n-b<b){
		c=0;
		c+=sum;
	}
	cout<<c;
	return 0;
}

