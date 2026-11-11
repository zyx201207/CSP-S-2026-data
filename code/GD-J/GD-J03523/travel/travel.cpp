#include<bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<"1";
			int a1=s1[2]-'A'+1;
			int a2=s2[2]-'A'+1;
			if(a1<=3&&a2<=3){
				cout<<"1";
				if(a1+1==a2||a1-1==a1){
					cout<<"1";
				}
				else {
					cout<<"0";
				}
			}
			else if(a1>3&&a2>3){
				cout<<"11";
			}
			else {
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	return 0;
} 
