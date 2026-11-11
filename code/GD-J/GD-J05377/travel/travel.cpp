#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char h1,h2;
	cin>>a>>b>>h1>>c>>d>>h2;
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if(((h1=='A'||h1=='B'||h1=='C')&&(h2=='A'||h2=='B'||h2=='C'))||((h1=='D'||h1=='F')&&(h2=='D'||h2=='F'))){
				cout<<1;
				if((h1=='D'&&h2=='F')&&(h2=='D'||h1=='F')){
					cout<<1;
				}else if(((h1=='A'||h1=='B'||h1=='C')&&(h2=='A'||h2=='B'||h2=='C'))&&(h1+1==h2||h1-1==h2)){
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
