#include<bits/stdc++.h>
using namespace std;
string s,c1,s1,c2,s2;
long long r1,x1,x,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x=s1[2],r=s2[2];
	if(c1!=c2) cout<<"0000";
	else{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(((x==65||x==66||x==67)&&(r==65||r==66||r==67))
			||((x==68||x==69)&&(r==68||r==69))){
				cout<<"1";
				if(abs(x-r)==1) cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}return 0;
}