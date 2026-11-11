#include<bits/stdc++.h>
using namespace std;
long long ghj(string s){
	string f;
	long long ans=0,i=0,sdf=s.size();
	sdf--;
	for(i=sdf;i>=0;i--){
		f=f+s[i];
	}
	
	for(i=0;i<s.size();i++){
		if(s[i]!=s[sdf-i-1]&&2*i<sdf){
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[20005],i=0,j=0;
	char b[20005];
	string s;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(j=0;j<a[i];j++){
			s+=b[i];
		}
	}
	cout<<ghj(s);
	return 0;
}
