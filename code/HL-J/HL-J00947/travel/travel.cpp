#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a1,b,b1;
	string s,s1;
	cin>>a>>a1>>b>>b1;
	if(a==b) {
		cout<<1;
		for(int i=0;i<2;i++){
			s+=a1[i];
			s1+=b1[i];
		}
		if(s==s1){
			cout<<1;
			if(a1[2]=='D'&&b1[2]=='C'||a1[2]=='C'&&b1[2]=='D'){
				cout<<"00";
				return 0;
			}
			else cout<<1;
			if(a1[2]+1==b1[2]||b1[2]+1==a1[2]) cout<<1;
			else cout<<0;
		}
		else cout<<"000";
	}
	else cout<<"0000";
}