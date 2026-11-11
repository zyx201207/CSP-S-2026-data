#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string pd;
	int kk=0;
	if(c1==c2){
		pd[0]='1';
	}else{
		pd[0]='0';
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&pd[0]=='1'){
		pd[1]='1';
	}else{
		pd[1]='0';
	}
	int hn=0;
	if(s1[2]<='c'&&s2[2]<='c'){
		hn=1;
	}else{
		if(s1[2]>='D'&&s2[2]>='D'){
			hn=1;
			}
		}
	if(pd[1]=='1'&&hn==1){
		pd[2]='1';
	}else{
		pd[2]='0';
	}
	
	if(s1[2]+1==s2[2]||s1[1]-1==s2[2]){
		kk=1;
	}
	if(pd[0]=='1'&&pd[1]=='1'&&pd[2]=='1'&&kk==1){
		pd[3]='1';
	}else{
		pd[3]='0';
	}
	cout<<pd[0]<<pd[1]<<pd[2]<<pd[3];
	return 0;
}
