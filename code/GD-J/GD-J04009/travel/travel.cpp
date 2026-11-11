#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c1,c2,l1,l2;
string s1,s2,p1,p2;
void solve(){
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return;
	}
	p1=s1.substr(0,2);
	p2=s2.substr(0,2);
	l1=s1[2]-'A';
	l2=s2[2]-'A';
	cout<<"1";
	if(p1!=p2){
		cout<<"000";
		return;
	}
	cout<<"1";
	if(l1<=2&&l2<=2){
		cout<<"1";
		if(l1==1||l2==1){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
		return;
	}
	if(l1>=3&&l2>=3){
		cout<<"11";
		return;
	}
	cout<<"00";
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
