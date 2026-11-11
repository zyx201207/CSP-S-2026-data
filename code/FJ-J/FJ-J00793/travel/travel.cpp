#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int l1=(s1[0]-'0')*10+s1[1],l2=(s2[0]-'0')*10+s2[1];
	char x1=s1[2],x2=s2[2];
	int ce1=(x1>='D'?1:0),ce2=(x2>='D'?1:0);
	if(c1==c2){
		cout<<1;
		if(l1==l2){
			cout<<1;
			if(ce1==ce2){
				cout<<1;
				if(abs(x1-x2)<=2) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else{
			cout<<"000";
		}
	}else cout<<"0000";
	return 0;
} 
