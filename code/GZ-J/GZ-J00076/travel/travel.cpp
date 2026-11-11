//GZ-J00076 贵阳市第三中学 吴钰辉 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	int a=int(s1[2]),b=int(s2[2]);
	if(a<68&&b<68){
		cout<<1;
	}
	else if(a>67&&b>67){
		cout<<1;
	}
	else {
		cout<<"00";
		return 0;
	}
	if(a+1==b||b+1==a)cout<<1;
	else cout<<0;
    return 0;
}

