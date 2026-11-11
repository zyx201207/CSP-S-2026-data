#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1!=c3){
		cout<<"0000";
	}else{
		string s1,s2;
		char a1,a2;
		for(int i=0;i<c2.size();i++){
			if(c2[i]>='0'&&c2[i]<='9') s1+=c2[i];
			else a1=c2[i];
		}
		for(int i=0;i<c4.size();i++){
			if(c4[i]>='0'&&c4[i]<='9') s2+=c4[i];
			else a2=c4[i];
		}
		if(s1!=s2){
			cout<<"1000";
		}else{
			if((a1>='A'&&a1<='C'&&a2>='D'&&a2<='F')||(a2>='A'&&a2<='C'&&a1>='D'&&a1<='F')){
				cout<<"1100";
			}
			else{
				if((abs(int(a1)-int(a2))==1&&a1!='D'&&a2!='D')||(a1=='D'&&a2=='F')){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}
		}
	}
	return 0;
}
