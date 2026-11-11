//GZ-J00437 张瑞晨 清华中学 
#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,t1,t2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	t1+=c2[0];t1+=c2[1];
	t2+=s2[0];t2+=s2[1];
	if(t1==t2)cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	char a=c2[2],b=s2[2];
	if((a<='C'&&b<='C')||(a>'C'&&b>'C'))cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(int(a-b)==1||int(a-b==-1))cout<<"1";
	else cout<<"0";
	return 0;
}
