#include<bits/stdc++.h>
using namespace std;
string c,s,c1,s1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	if(c[0]==c1[0]&&c[1]==c1[1]){
		cout<<1;
		if(s[0]==s1[0]&&s[1]==s1[1]){
		    cout<<1;
		    if(s[2]<='C'&&s1[2]<='C'){
		        cout<<1;
		        if(s[2]-s1[2]==1||s1[2]-s[2]==1)cout<<1;
		        else cout<<0;
		    }else if(s[2]>='D'&&s1[2]>='D'){
		        cout<<1;
		        if(s[2]-s1[2]==1||s1[2]-s[2]==1)cout<<1;
		        else cout<<0;
		    }else cout<<"00";
	    }else cout<<"000";
	}else cout<<"0000";
	return 0;
}
