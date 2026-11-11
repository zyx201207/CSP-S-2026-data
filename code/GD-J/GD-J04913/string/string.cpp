#include<bits/stdc++.h>
using namespace std;
string s,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k,m=0,p=0;
	char a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		cin>>a;
		for(int f=0;f<k;f++){
			s[m]=a;
			m++;
		}
	}
	for(int i=m-1;i>=0;i--){
		for(int f=0;f<m;f++){
			s2[i]=s[f];
		}
	}
	for(int i=0;i<m;i++){
		if(s[i]!=s2[i]){
			p++;
		}
	}
	cout<<p/2;
	return 0;
}
