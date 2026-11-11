#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n,a=0,b,d=0;
string S,S2;
char c;
cin>>n;
for(int i=1;i<=n;i++){
	cin>>b>>c;
	for(int j=1;j<=b;j++){
	    S[a]=c;
		a++; 
	}
}
for(int j=0;j<a;j++){
	S2[j]=S[a-1];
	a--;
}
for(int j=0;j<a;j++){
	if(S2[j]!=S[j])
	d++;
}
cout<<d;
return 0;
}
