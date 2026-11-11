#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			int f1,f2;	//过道的哪一侧
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				f1=1;	//A，B，C一侧
			}if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				f2=1;	//A，B，C一侧
			}if(s1[2]=='D'||s1[2]=='E'){
				f1=2;	//D，E一侧
			}if(s2[2]=='D'||s2[2]=='E'){
				f2=2;	//D，E一侧
			}
			if(f1!=f2){
				cout<<"00";
			}else{
				cout<<"1";
				if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
					cout<<"0";
				}else{
					cout<<"1";
				}
			}
		}else{
			cout<<"000";
		}
	}
	return 0;
}
