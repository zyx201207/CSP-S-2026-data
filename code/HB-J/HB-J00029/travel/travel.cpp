#include <bits/stdc++.h>
using namespace std;
int c1,c2,p1,p2;
char w1,w2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>p1>>w1>>c2>>p2>>w2;
	//cout<<c1<<" "<<p1<<" "<<w1<<"\n";
	//cout<<c2<<" "<<p2<<" "<<w2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(p1==p2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((w1<='C'&&w2<='C')||(w1>='D'&&w2>='D')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((w1=='D'&&w2=='F')||(w1=='F'&&w2=='D')||(w1=='A'&&w2=='B')||(w2=='A'&&w1=='B')||(w1=='B'&&w2=='C')||(w2=='B'&&w1=='C')) cout<<1;
	else cout<<0;
	return 0;
}
