#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,o=0;
	cin >>n;
	int a[n];
	char b[n];
	string s;
	for(int i=0;i<n;i++){
		cin >>a[i] >>b[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[n-1-i]){
			o++;
		}
	}
	cout <<o;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
