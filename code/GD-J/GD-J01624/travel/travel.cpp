#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
bool f[10][10];
bool f1[10][10];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	f[1][2]=true,f[1][3]=true,f[2][3]=true,f[2][1]=true,f[3][1]=true,f[3][2]=true,f[4][5]=true,f[5][4]=true;
	f1[1][2]=true,f1[2][1]=true,f1[2][3]=true,f1[3][2]=true,f1[4][5]=true,f1[5][4]=true;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	int o1=s1[2]-'A'+1,o2=s2[2]-'A'+1;
	if(f[o1][o2]==true){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(f1[o1][o2]==true){
		cout<<1;
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
} 
