#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ans[5]={0};

bool is_left(string s){
	if(s[2]=='A'||s[2]=='B'||s[2]=='C')
		return true;
	return false;
}


bool is_near(string s1,string s2){
	return abs(s1[2]-s2[2])==1;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[1]=true;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1<<' ';
			if(is_left(s1)==is_left(s2)){
				ans[3]=true;
				if(is_near(s1,s2)){
					ans[4]=true;
				}
			}
		}
		else cout<<0<<' ';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(is_left(s1)==is_left(s2)){
				ans[3]=true;
				if(is_near(s1,s2)){
					ans[4]=true;
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		if(i!=2)
			cout<<ans[i]<<' ';//Trick||Treat!
	}
	return 0;
}
