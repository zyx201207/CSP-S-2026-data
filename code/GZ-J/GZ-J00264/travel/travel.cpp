//GZ-J00264 ≥¬ич–щ
#include<bits/stdc++.h>
using namespace std;
int a1,a2;
string b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		cout<<1;
		if(b1[0]==b2[0]&&b1[1]==b2[1]){
			cout<<1;
			if('A'<=b1[2]&&b1[2]<='C'&&'A'<=b2[2]&&b2[2]<='C'||'D'<=b1[2]&&b1[2]<='F'&&'D'<=b2[2]&&b2[2]<='F'){
				cout<<1;
				if(b1[2]-b2[2]==1||b1[2]-b2[2]==-1||b1[2]=='D'||b1[2]=='F'){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
