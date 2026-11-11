#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	int s=0;
	int c,d;
	char e,f;
	cin>>a>>c>>e>>b>>d>>f;
	if(a==b){
		cout<<'1';
		s++;
		if(c==d){
			cout<<'1';
			s++;
			if(!((e=='C'&&f=='D') || (e=='D'&&f=='C'))){
				cout<<'1';
				s++;
				if(e==f+1||e+1==f){
					cout<<'1';
					s++;
				}
			}
		}
	}
	for(int i=0;i<(4-s);i++){
		cout<<'0';
	}
	return 0;
}
