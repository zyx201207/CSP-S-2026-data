#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string x1,x2,y1,y2,l1,l2;
	char e1,e2;
	cin>>x1>>y1>>x2>>y2;
	//bool ans1,ans2,ans3,asn4;
	if(x1!=x2){
		cout<<"0000";
		return 0;
	}
	l1=y1.substr(0,2);
	l2=y2.substr(0,2);
	if(l1!=l2){
		cout<<"1000";
		return 0;
	}
	e1=y1[2];
	e2=y2[2];
	bool p1=(e1<='C'),p2=(e2<='C');
	if(p1!=p2){
		cout<<"1100";
		return 0;
	}
	if(abs(e1-e2)>1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
