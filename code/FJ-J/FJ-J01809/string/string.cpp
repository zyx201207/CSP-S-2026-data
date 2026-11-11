#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	long long a[100000];
	char b[100000];
	int ascii[100000]; 
	for(long int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	long long h=0;
	string s;
	for(long int i=0;i<n;i++){
		if(b[0]==b[i]){
			h++;
		}
	}
	if(h==n){
		cout<<"0";
		return 0;
	}
	for(long int i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			s+=b[i];
		}
	}
	long long p=0;
	long long k=0;
	for(long int i=0;i<n;i++){
		p+=a[i];
	}
	if(p%2==0){
		p--;
	}
	for(long int i=0;i<s.size();i++){
		if(i>=p-i){
			break; 
		}
		if(s[i]!=s[p-i]){
			k++;
		}
	}
	cout<<k;
	return 0;
}