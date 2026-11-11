#include<bits/stdc++.h>
using namespace std;
int a,b,e,f;
char c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>e>>c>>b>>f>>d;
	if(a==b){
		cout<<1;
		if(e==f){
			cout<<1;
			if((c<='C'&&d<='C')||(c>='D'&&d>='D')){
				cout<<1;
				int g=c,h=d;
				if(abs(g-d)==1||(c>='D'&&d>='D')){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
