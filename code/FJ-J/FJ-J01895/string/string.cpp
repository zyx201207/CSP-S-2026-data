#include<bits/stdc++.h>
using namespace std;
string s;
int l,b,n,a;
char c;
int main(){
	freopen("string1.in","r",stdin);
	freopen("string1.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			l++;
	    	s[l]=c;}}
    int d;
    if(l%2==1) d=(l-1)/2;
    else d=l/2;
    for(int i=1;i<=d;i++){
    	if(s[i]!=s[l]){
    		b++;}
		l--;
	}
	cout<<b;
	return 0;
}
