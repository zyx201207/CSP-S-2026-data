//GZ-J00246 华东师范大学附属贵阳学校 杨昊宸
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int rc,rs,xc,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();++i){
		rc*=10;
		rc+=int(c1[i]-'0');
	}
	for(int i=0;i<c2.size();++i){
		xc*=10;
		xc+=int(c2[i]-'0');
	}
	int len=s1.size();
	for(int i=0;i<len-1;++i){
		rs*=10;
		rs+=int(s1[i]-'0');
	}
	len=s2.size();
	for(int i=0;i<len-1;++i){
		xs*=10;
		xs+=int(s2[i]-'0');
	}
	if(rc==xc){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(rs==xs){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char rh=s1[2],xh=s2[2];
	if('A'<=rh<='C'&&'A'<=xh<='C'){
		cout<<1;
	}else if('D'<=rh<='F'&&'D'<=xh<='F'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((rh==xh+1)||(rh+1==xh)){
		cout<<1;
	}else{
		cout<<0;
	}
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
