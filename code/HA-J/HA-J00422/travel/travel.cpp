#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char n,m;
	cin>>a>>b>>n>>c>>d>>m;
	if(a==c){
		cout<<"1";
		if(b==d){
			cout<<"1";
			if(((n=='D'||n=='F')&&(m=='C'||m=='A'||m=='B'))||((m=='D'||m=='F')&&(n=='A'||n=='B'||n=='C'))){
				cout<<"00";
			}else if((n=='A'&&m=='C')||(n=='C'&&m=='A')){
				cout<<"10";
			}else{
				cout<<"11";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
