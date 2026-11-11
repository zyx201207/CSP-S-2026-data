#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool t,y;
int main(){
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]>='A'&&s1[2]<='C'){
		t=1;
	}
	if(s2[2]>='A'&&s2[2]<='C'){
		y=1;
	}
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(t==y){
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
					cout<<1;
				}else cout<<0;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	return 0;
}
