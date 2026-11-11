#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string x1,x2,y1,y2;
	cin>>x1>>x2>>y1>>y2;
	if(x1==y1){
		cout<<'1';
		if(x2[0]==y2[0]&&x2[1]==y2[1]){
			cout<<'1';
			if((x2[2]=='A'||x2[2]=='B'||x2[2]=='C')&&(y2[2]=='A'||y2[2]=='B'||y2[2]=='C')){
				cout<<'1';
				if(abs(x2[2]-y2[2])==1)cout<<'1';
				else cout<<'0';
			}
			else if((x2[2]=='D'||x2[2]=='F')&&(y2[2]=='D'||y2[2]=='F'))cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
