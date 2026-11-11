#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    string t1=s1.substr(0,2);
    string t2=s2.substr(0,2);
    if(t1!=t2){
        cout<<"1000";
        return 0;
    }
    char x=s1[2],y=s2[2];
    bool b1=(x<='C'),b2=(y<='C');
    if(b1!=b2){
		cout<<"1100";
		return 0;
	}
	if(abs(x-y)>1) cout<<"1110";
	else cout<<"1111";
	return 0;
}//100+72+65+0=237
