//GZ-J00106 贵阳市清华中学 周子骏
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ll c1,c2;
    string s1,s2;
	cin>>c1>>s1>>c2>>s2;
    if(c1==c2&&c1!=1&&c1!=16&&c1<=17&&c1>=1){
    	cout<<1;
    	if(s1[0]==s2[0]&&s1[1]==s2[1]){
    		cout<<1;
    		if((s1[2]-'C'<=0&&s2[2]-'C'<=0)||(s1[2]-'C'>0&&s2[2]-'C'>0)){
    			cout<<1;
    			if(s1[2]-'C'>0&&s2[2]-'C'>0)cout<<1;
    			else if(s1[2]=='B'||s2[2]=='B')cout<<1;
    			else cout<<0;
			}else cout<<"00";
		}
		else cout<<"000";
	}else{
		cout<<"0000";
	}
    return 0;

}
