#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b;
char sit1[10],sit2[10];
bool near=false,in=false;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	scanf("%s",sit1);
	cin>>b;
	scanf("%s",sit2);
	
	if(a==b) {
		cout<<"1";
		in=true;
	}
	else cout<<"0";
	
	if(in&&sit1[0]==sit2[0]&&sit1[1]==sit2[1]) {
		cout<<"1";
		near=true;
	}
	else cout<<"0";
	
	if(near&&((sit1[2]<='C'&&sit2[2]<='C')||(sit1[2]>'C'&&sit2[2]>'C'))) cout<<"1";
	else cout<<"0";
	
	if(near&&((sit1[2]=='F'&&sit2[2]=='D'||sit1[2]=='D'&&sit2[2]=='F')||(sit1[2]=='B'&&sit2[2]=='C'||sit1[2]=='C'&&sit2[2]=='B')||(sit1[2]=='A'&&sit2[2]=='B'||sit1[2]=='B'&&sit2[2]=='A'))) cout<<"1";
	else cout<<"0";
	return 0;
}
