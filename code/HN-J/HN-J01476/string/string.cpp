#include <bits/stdc++.h>
using namespace std;
long long n,a[20000010],sum;
string s,c,v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}for(long long i=0;i<n;i++){
		for(long long j=1;j<=a[i];j++){
			c+=s[i];
		}
	}
	for(long long i=0;i<c.size();i++){
		v+=c[c.size()-i-1];
		
	}if(v==c){
		cout<<0;
		return 0;
	}
	for(long long i=0;i<c.size();i++){
		if(v[i]!=c[i]){
			v[i]=c[i];
			sum++;
		}else{
			break;
		}if(v==c){
			break;
		}
		
	}
	cout<<sum;
} 
