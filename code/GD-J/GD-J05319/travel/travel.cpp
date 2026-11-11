#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	char cmax=max(s1[2],s2[2]),cmin=min(s1[2],s2[2]);
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(cmax=='D'){
				cout<<"00";
			}else{
				cout<<1;
				if(cmax-cmin==1||(cmax=='F'&&cmin=='D')){
					cout<<1;
				}else{
					cout<<"0";
				}
			}
		}else{
			cout<<"000";
		}
	}
	return 0;
}
