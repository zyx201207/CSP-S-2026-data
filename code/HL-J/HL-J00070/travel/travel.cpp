#include<bits/stdc++.h>
using namespace std;
int chexiang[20],c1,c2;
string s1,s2;
int ans[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[1]=1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		ans[2]=1;
	}
	else{
		cout<<"1000";
		return 0;
	}
	char a=s1[2],b=s2[2];
	if(a=='D'&&b=='F'||a=='F'&&b=='D'){
		ans[3]=1;
	}
	else{
		if(a=='A'&&b=='B'||a=='B'&&b=='C'||a=='A'&&b=='C'||b=='A'&&a=='B'||b=='B'&&a=='C'||b=='A'&&a=='C'){
			ans[3]=1;
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	if(abs(int(a-b))==1){
		ans[4]=1;
	}
	else{
		cout<<"1110";
		return 0;
	}
	cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
	return 0;
}