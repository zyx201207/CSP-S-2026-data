#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;//c车厢号 s座位号
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//车厢t 
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	//同排t 
	bool l1=0,l2=0;
	if(s1[2]>='A'&&s1[2]<='C') l1=1;
	if(s2[2]>='A'&&s2[2]<='C') l2=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
		//同侧f 
		if(l1==l2){
			cout<<"1";
		}else cout<<"0"; 
	}else cout<<"00";
	int x=(s1[0]-'0')*10+s1[1]-'0',y=(s2[0]-'0')*10+s2[1]-'0';
	if(l1==l2){
		if(s1[2]-s2[2]==1&&x==y||s2[2]-s1[2]==1&&x==y||x-y==1&&s1[2]==s2[2]||y-x==1&&s1[2]==s2[2]) cout<<"1";
		else cout<<"0";
	}else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
