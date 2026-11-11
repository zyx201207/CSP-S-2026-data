#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int a1,a2,p1,p2;
bool check(){
	int f1=0,f2=0;
	if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C') f1=1;
	else f1=0;
	if(c4[2]=='A'||c4[2]=='B'||c4[2]=='C') f2=1;
	else f2=0;
	return f1==f2;
}
bool che(){
	int f1=0,f2=0;
	if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C') f1=1;
	else f1=0;
	if(f1==1){
		if(abs((int)c2[2]-c4[2])==1) return 1;
		else return 0;
	}
	else return 1;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>c2>>c3>>c4;
	if(c1[0]=='0') a1=c1[1]-'0';
	else a1=(c1[0]-'0')*10+c1[1]-'0';
	if(c3[0]=='0') a2=c3[1]-'0';
	else a2=(c3[0]-'0')*10+c3[1]-'0';
	if(c2[0]=='0') p1=c2[1]-'0';
	else p1=(c2[0]-'0')*10+c2[1]-'0';
	if(c4[0]=='0') p2=c4[1]-'0';
	else p2=(c4[0]-'0')*10+c4[1]-'0';
	if(a1==a2){
		cout<<1;
		if(p1==p2){
			cout<<1;
			if(check()){
				cout<<1;
				if(che()) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
