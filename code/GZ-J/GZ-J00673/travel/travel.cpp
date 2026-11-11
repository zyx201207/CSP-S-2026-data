//GZ-J00673 遵义市第四初级中学  刘俊翔
#include<bits/stdc++.h>
using namespace std;
char tc(string a,string b){
	if(a[2]!='F'&&b[2]!='F'){
		if(a[2]!='D'&&b[2]!='D'){
				return '1';
		}else{
			return '0';
		}
	}else{
		if(a[2]=='D'||b[2]=='D'){
			return '1';
		}else{
			return '0';
		}
	}
}
char xl(string a,string b){
	int mx=INT_MIN,mn=INT_MAX;
	if(a[2]!='F'&&b[2]!='F'){
		if(a[2]!='D'&&b[2]!='D'){
			mx=max((int)a[2],(int)b[2]);
			mn=min((int)a[2],(int)b[2]);
			if(mx-mn==1){
				return '1';
			}
			return '0';
		}else{
			return '0';
		}
	}else{
		if(a[2]=='D'||b[2]=='D'){
			return '1';
		}else{
			return '0';
		}
	}
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string s1,s2,s3,s4,ss[5];
	cin>>s1>>s2>>s3>>s4;
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s3[i]){
			ss[0]='0';
			break;
		}
		ss[0]='1';
	}
	if(ss[0]=="0"){
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s2.size()-1;i++){
	    if(s2[i]!=s4[i]){
	    	ss[1]='0';
	    	break;
		}
		ss[1]='1';
	}
	if(ss[1]=="0"){
		cout<<ss[0]<<"000";
		return 0;
	}
	ss[2]=tc(s2,s4);
	ss[3]=xl(s2,s4);
	for(int i=0;i<=4;i++){
		cout<<ss[i];
	}
}
