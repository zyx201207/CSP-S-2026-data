#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,j=0,ss=0;cin>>a;string s;
	for(int i=1;i<=a;i++){
		int b;char c;cin>>b>>c;
		for(;b>0;b--){
			j++;
			s[j]=c;
		}}
		int b,c;
	if(j%2==0){
		b=j/2;c=j/2+1;
		for(;b>=1;){
			if(s[b]!=s[c])ss++;
			b--;c++;
		}
	}
	else{
		b=j/2;c=j/2+2;
		for(;b>=1;){
			if(s[b]!=s[c])ss++;
			b--;c++;
		} 
	}
	cout<<ss;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
