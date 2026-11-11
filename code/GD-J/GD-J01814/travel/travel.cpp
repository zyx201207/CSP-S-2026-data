#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N = 1e6 + 5;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int x1,x2;
	char y1,y2;
	cin>>c1>>s1>>c2>>s2;
	x1=(s1[0]-'0')*10+(s1[1]-'0');
	x2=(s2[0]-'0')*10+(s2[1]-'0');
	y1=s1[2];
	y2=s2[2];
	if(c1==c2){
		cout<<"1";
		if(x1==x2){
			cout<<"1";
			if(((y1>='A'&&y1<='C')&&(y2>='A'&&y2<='C'))||((y1>='D'&&y1<='F')&&(y2>='D'&&y2<='F'))){
				cout<<"1";
				if(abs(y1-y2)==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	} 
	else cout<<"0000";
	return 0;
} 
