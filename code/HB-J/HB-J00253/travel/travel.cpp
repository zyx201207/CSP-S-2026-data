#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int flag=0,f2=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		f2=1;
		cout<<1;
	}else cout<<0;
	if(f2==1){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')) cout<<1,flag=1;
			else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')) cout<<11;
			else cout<<"00";
			if(flag==1){
				if(abs(int(s1[2]-s2[2]))==1) cout<<1;
				else cout<<0;
			}
		}else{
			cout<<"000";
		}
	}else cout<<"000";
	return 0;
}
