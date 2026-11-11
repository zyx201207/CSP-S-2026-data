#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1,s2;
int a,b;
int main(){
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	cin>>c1;
	cin>>a>>s1;
	cin>>c2;
	cin>>b>>s2;
	if(c1==c2){
		cout<<1;
		if(a==b){
			cout<<1;
			int x=s1;
			int y=s2;
			if((x<=67&&y<=67)||(x>=68&&y>=68)){
				cout<<1;
				if((x-y==1||y-x==1)){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
}
