#include<bits/stdc++.h>
using namespace std;
int c1,c2;
int tyc,tcx,typ;
string s1,s2;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		tcx=1;
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(tcx==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
		tyc=1;
	}else{
		cout<<"0"; 
	}
	if(tyc==1&&(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')))){
		cout<<"1";
		typ=1;
	}else{
		cout<<"0";
	}
	if((typ==1)&&(((max(s1[2],s2[2])-min(s1[2],s2[2]))==1)&&!((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
