#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,h1,h2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	for(int i=0;i<s1.size()-1;i++) h1[i]=s1[i];
	for(int i=0;i<s2.size()-1;i++) h2[i]=s2[i];
	if(h1==h2) cout<<1;
	else cout<<0;
	char a=s1[2],b=s2[2];
	if(h1==h2){
		if(a>='A' && a<='C' && b>='A' && b<='C') cout<<1;
		else if(a>='D' && a<='F' && b>='D' && b<='F') cout<<1;
		else cout<<0;
	}
	if(a+1==b || a-1==b) cout<<1;
	else cout<<0;
	return 0;
}
