#include<bits/stdc++.h>

using namespace std;
string ans;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	//t1
	if(c1==c2)ans+='1';
	else ans+='0';
	//t2
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2)ans+='1';
	else ans+='0';
	//t3
	if((s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D')&&s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2){
		ans+='1';
	}else{
		ans+='0';
	}
	//t4
	if(s1[2]<='C'&&s2[2]<='C'){
		if((s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2)&&int(abs(s1[2]-s2[2]))==1){
			ans+='1';
		}else{
			ans+='0';
		}
	}else if(s1[2]>='D'&&s2[2]>='D'){
		if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2){
			ans+='1';
		}else{
			ans+='0';
		}
	}else{
		ans+='0';
	}
	cout<<ans;
	return 0; 
}
