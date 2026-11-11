#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c1,h1,c2,h2;
char s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&c1,&h1,&s1,&c2,&h2,&s2);
	if(c1==c2){
		cout<<1;
		if(h1==h2){
			cout<<1;
			if((s1<='C'&&s2<='C')||(s1>='D'&&s2>='D')){
				cout<<1;
				if(!((s1=='A'&&s2=='C')||(s2=='A'&&s1=='C'))) cout<<1<<'\n';
				else cout<<0<<'\n';
			}else cout<<"00"<<'\n';
		}else cout<<"000"<<'\n';
	}else cout<<"0000"<<'\n';
	return 0;
}
