#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0,a[100100];
	long long l=0,z=0;
	char c[100100];
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
			l++;
		}
	}
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			s[l-i-1]=s[i];
			z++;
		}
	}
	cout<<z;
	return 0;
}
