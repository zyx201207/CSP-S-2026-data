#include<bits/stdc++.h>
using namespace std;
int check(string a,string b){
	int cnt=0;
	for(int i=0;i<a.length();i++){
		if(a[i]!=b[i]) cnt++;
	}
	return cnt;
}
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string m,s;
	int n,t;
	char a;	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t>>a;
		s+=t*a;
	}
	int j=0;
	if(s.length()%2==1){
		j=1;
		for(int i=0;i<s.length();i++){
			if(i==s.length()/2+1) continue;
			m[i]=s[i];
		}
	}else m=s;
	
	string ds;
	int k=0;
	for(int i=s.length()-1-j;i>=0;i--){
		ds[i]=m[k];
		k++;
	}
	cout<<m<<ds;
	cout<<check(m,ds);
}
