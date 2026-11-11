#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool p=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	ios::sync_with_stdio(false);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			p=0;
			break;
		}
	}
	if(p)cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	if(s1[2]>='D'&&s2[2]>='D'){
		cout<<'1';
	}
	else if(s1[2]<'D'&&s2[2]<'D'){
		cout<<'1';
	}
	else{
		cout<<"00";
		return 0;
	}
	if(s1[2]+1==s2[2]||s1[2]==s2[2]+1){
		cout<<'1';
	}
	else cout<<'0';
	return 0;
}
