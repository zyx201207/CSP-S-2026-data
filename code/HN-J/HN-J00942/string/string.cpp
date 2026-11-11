#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		string y;
		cin>>x;
		cin>>y;
		for(long long i=1;i<=x;i++){
			s+=y;
		}
	}
	bool flag=true;
	long long h=s.length();
	for(long long i=0;i<=h/2;i++){
		if(s[i]!=s[h-i]){
			flag=false;
		}
	}
	if(flag){
		cout<<0;
	}
	else {
		long long q=0;
		if(h%2==0){
			for(long long i=0;i<h/2;i++){
				if(s[i]!=s[h-i]){
					s[n+1-i]=s[i];
					q++;
					
				}
			}	
		}
		else {
			for(long long i=0;i<h/2+1;i++){
				if(s[i]!=s[h-i]){
					q++;
				}
			}
		}
		cout<<q;
	}
}
