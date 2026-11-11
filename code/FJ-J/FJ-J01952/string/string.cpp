#include<bits/stdc++.h>
using namespace std;
int n,c=0;
int a[200009]; 
char s[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]!=s[n-i]){
			s[n-1]=s[i];
			c++;
		}
	}
	cout<<c;
	return 0;
}

