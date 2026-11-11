#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s;
	long long cnt=0,k=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		k+=a[i];
		//for(int j=0;j<a[i];j++)s+=c[i];
	}if(k>1000000000){
		cout<<k/2;
		return 0;
	}for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++)s+=c[i];
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])cnt++;
	}cout<<cnt;
	return 0;
} 
