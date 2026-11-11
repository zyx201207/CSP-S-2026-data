#include<bits/stdc++.h>
using namespace std;
long long n,m,len;
string s="",c="",a="";
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin >> n;
	for(long long i=0;i<n;i++){
	cin >> m>>c;
		for(int i=0;i<m;i++){
			a+=c;
		}
	}
	for(int i=a.size()-1;i>=0;i--){
		s+=a[i];
	}
	if(a==s){cout<<0;return 0;}
	len=s.size()/2;
	for(int i=0;i<len;i++){
		if(s[i]!=a[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
