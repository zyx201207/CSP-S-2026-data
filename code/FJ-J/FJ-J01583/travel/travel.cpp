#include<bits/stdc++.h>
using namespace std;

struct tr{
	int che;
	string chiar;
	int op;
	int seat;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	tr a,b;
	cin>>a.che>>a.chiar>>b.che>>b.chiar;
	a.seat=a.chiar[2]-'A';
	b.seat=b.chiar[2]-'A';
	if(a.seat<=2) a.op=0;
	else a.op=1;
	if(b.seat<=2) b.op=0;
	else b.op=1;
	if(a.che==b.che){
		cout<<1;
		if(a.chiar[1]==b.chiar[1]){
			cout<<1;
			if(a.op==b.op){
				cout<<1;
				if(abs(a.seat-b.seat)==1)
					cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
