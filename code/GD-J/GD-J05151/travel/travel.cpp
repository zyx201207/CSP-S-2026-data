#include<bits/stdc++.h>
using namespace std;

struct aa{
	int a;
	int b;
	char c;
};

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	aa r;
	aa x;
	
	cin>>r.a>>r.b>>r.c;
	cin>>x.a>>x.b>>x.c;
	
	if(r.a==x.a){
		cout<<1;
		if(r.b==x.b){
			cout<<1;
			if((r.c>='A' && r.c<='C' && x.c>='A' && x.c<='C') || (r.c>='D' && r.c<='E' && x.c>='D' && x.c<='E')){
				cout<<1;
				if(r.c+1==x.c || r.c-1==x.c){
					cout<<1;
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
} 
