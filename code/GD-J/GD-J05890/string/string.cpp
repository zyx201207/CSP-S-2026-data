#include<bits/stdc++.h>
using namespace std;
int n,a,m,sum=0;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s='0';
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s=s+c;
		}
	}
	m=s.size()-1;
	for(int i=1;i<=m/2;i++){
		if(s[m-i+1]!=s[i]){
			sum++;
		}
	}
	cout<<sum;
}
