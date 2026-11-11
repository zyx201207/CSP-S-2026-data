#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<"1";
	int f1=(s1[0]-'0')*10+(s1[1]-'0'),f2=(s2[0]-'0')*10+(s2[1]-'0'),j1=(s1[2]-'A'+1),j2=(s2[2]-'A'+1);
	if(f1==f2){
		cout<<"1";
		if((j1<=3&&j2<=3)||(j1>3&&j2>3)){
			cout<<"1";
			if(abs(j1-j2)==1)cout<<"1";
			else cout<<"0";
		}
		else cout<<"00";
	}
	else cout<<"000";
	return 0;
} 
