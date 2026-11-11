#include<bits/stdc++.h>
using namespace std;
string s1,s2;
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,x=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s1=s1+b;
		}
	}
	for(int i=s1.size()-1;i>=0;i--){
		s2+=s1[i];
	}
	int m=s1.size();
	for(int i=0;i<m>>1;i++){
		if(s1[i]!=s2[i]){
			x++;
		}
	}
	cout<<x;
	return 0;
}
