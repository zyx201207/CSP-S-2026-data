#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int t1,t2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1[0]==c2[0]&&c1[1]==c2[1]){
		ans="1";
	}else{
		ans="0";
	}
	if (s1[0]==s2[0]&&s1[1]==s2[1]&&ans[0]=='1'){
		ans+="1";
	}else{
		ans+="0";
	}
	if (s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		t1=1;
	}else{
		t1=2;
	}
	if (s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		t2=1;
	}else{
		t2=2;
	}
	if (t1==t2&&ans[0]=='1'&&ans[1]=='1'){
		ans+="1";
	}else{
		ans+="0";
	}
	if (ans[0]=='1'&&ans[1]=='1'&&ans[2]=='1'&&max((int)s1[2],(int)s2[2])-min((int)s1[2],(int)s2[2])==1){
		ans+="1";
	}else{
		ans+="0";
	}
	cout<<ans;
	return 0;
}
