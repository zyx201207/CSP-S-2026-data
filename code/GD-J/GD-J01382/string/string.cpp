#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200008];
char c[200008];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	s[0]='';
	for(int i=1;  i<=n ; i++){
		cin >>a[i]>>c[i];
		int imp=s.size();
		for(int j=imp ; j<=imp+a[i] ; j++){
			s[j]=c[i];
		} 
	}
	long long ans=0;
	for(int i=s.size()/2-1 ; i<=s.size()-1 ; i++){
		if(s[i]!=s[s.size()-1+1-i] && (s.size()-1+1-i!=0)){
			s[s.size()-1+1-i]=s[i];
			ans++;
		}
	}
	cout <<ans;
	
	
	return 0;
} 
