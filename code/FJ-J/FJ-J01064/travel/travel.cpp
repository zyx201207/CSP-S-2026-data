#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    bool flag1=c1==c2 ? 1 : 0;
    bool flag2=(s1[0]==s2[0] && s1[1]==s2[1]) ? 1 : 0;
    bool flag3=((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D')) ? 1 : 0;
    bool flag4=(abs(s1[2]-s2[2])==1 && s1[2]+s2[2]!='C'+'D') ? 1 : 0;
    if(flag1){
    	cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(flag2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(flag3){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(flag4){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
/*
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
02 02B 02 01A
02 01A 03 01A
*/
