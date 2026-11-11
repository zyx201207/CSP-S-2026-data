#include<bits/stdc++.h>
using namespace std;

int a,b;
int x,y;
char p,q;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>p>>b>>y>>q;
	if(a!=b){
		cout<<"0000";
	}
	else{
		cout<<1;
		if(x!=y){
			cout<<"000";
		}
		else{
			cout<<1;
			if(q>p)
				swap(q,p);
			if(p<='C'||q>'C'){
				cout<<1;
				if(abs(p-q)==1)
					cout<<1;
				else
					cout<<0;
			}
			else{
				cout<<"00";
			}
		}
	}
	return 0;
}
