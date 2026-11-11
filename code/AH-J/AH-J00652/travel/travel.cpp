#include<bits/stdc++.h>
using namespace std;
bool check(char q,char w,int op){
	if(q>w) swap(q,w);
	if(q=='D'&&w=='F') return true;
	if(q=='A'&&w=='B') return true;
	if(q=='B'&&w=='C') return true;
	if(q=='A'&&w=='C'&&op==1) return true;
	return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string C,A,D,B;
	cin>>C>>A>>D>>B;
	string E=A.substr(0,2);
	string F=B.substr(0,2);
	char G=A[2],H=B[2];
	if(C==D){
		cout<<"1";
		if(E==F){
			cout<<"1";
			if(check(G,H,1)==true) cout<<"1";
			else cout<<"0";
			if(check(G,H,2)==true) cout<<"1";
			else cout<<"0";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
