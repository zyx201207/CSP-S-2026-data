//GZ-J00525 兴义市弘毅中学 龙乙夫
#include<bits/stdc++.h>
using namespace std;
string c[2];
string s[2];
int ans[4]={0,0,0,0};
char r[3]={'A','B','C'};
char l[2]={'D','F'};
bool is_ss(char a,char b){
	char ar,br;
	for(int i=0;i<3;i++){
		if(a==r[i])ar='r';
		if(b==r[i])br='r';
	}
	for(int i=0;i<2;i++){
		if(a==l[i])ar='l';
		if(b==l[i])br='l';
	}
	return ar==br;
}
bool is_near(char a,char b){
	if(a<='C'&&b<='C'){
		if(a-b==1||b-a==1){
			return true;
		}
	}
	else if(a>='D'&&b>='F'){
		if(a-b==2||b-a==2){
			return false;
		}
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[0]>>s[0];
	cin>>c[1]>>s[1];
	if(c[0]==c[1]){
		ans[0]=1;
		if(s[0][0]==s[1][0]&&s[0][1]==s[1][1]){
			ans[1]=1;
			if(is_ss(s[0][2],s[1][2])){
				ans[2]=1;
				if(is_near(s[0][2],s[1][2])){
					ans[3]=1;
				}
			}
		}
	}
	for(int i=0;i<4;i++)cout<<ans[i];
	cout<<endl;
	return 0;
} 
