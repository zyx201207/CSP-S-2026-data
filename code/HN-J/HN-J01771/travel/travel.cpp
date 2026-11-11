#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1]){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	}
	if(s2[0]!=s1[0]||s1[1]!=s2[1]){
		cout<<"000";
		return 0;
	}else{
		cout<<"1";
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		cout<<"1";
	}else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	string t="ABCDF";
	int a,b;
	for(int i=0;i<5;i++){
		if(s1[2]==t[i]){
			a=i;
			break;
		}
	}
	for(int i=0;i<5;i++){
		if(s2[2]==t[i]){
			b=i;
			break;
		}
	}
	if(a-b==1||a-b==-1){
		if((a==2&&b==3)||(a==3&&b==2)){
			cout<<"0";
		}else{
			cout<<"1";
		}
	}else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
