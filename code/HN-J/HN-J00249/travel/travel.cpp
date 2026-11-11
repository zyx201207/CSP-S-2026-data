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
		if(b1[0]==b2[0] and b1[1]==b2[1]){
			cout<<1;
			if(((b1[2]>='A' and b1[2]<='C') and (b2[2]>='A' and b2[2]<='C'))){
				cout<<1;
				if(b1[2]+1==b2[2] or b1[2]-1==b2[2]) cout<<1;
				else cout<<0;
			}else if(((b1[2]=='D' and b2[2]=='F') or (b1[2]=='F' and b2[2]=='D')))cout<<11;
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
