#include<bits/stdc++.h>
using namespace std;
int n;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int x,a=0,d=0;
	char y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		for(int j=x;j<=x+x-1;j++){
			s[j]=y;
			d++;
		} 
	}
	for(int i=1;i<=d;i++){
		if(s[i-1]!=s[d-i]){
			s[d-i]=s[i-1];
			a++;
		}
	}
	cout<<a;
	return 0;
} 
