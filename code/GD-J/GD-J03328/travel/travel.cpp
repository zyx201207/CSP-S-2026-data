#include<bits/stdc++.h>
using namespace std;
string c1,c2,id1,id2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>id1>>c2>>id2;
	if(c1==c2){
		if(id1[0]==id2[0]&&id1[1]==id2[1]){
			bool t1,t2;
			if(id1[2]=='A'||id1[2]=='B'||id1[2]=='C') t1=0;
			else t1=1;
			if(id2[2]=='A'||id2[2]=='B'||id2[2]=='C') t2=0;
			else t2=1;
			if(t1==t2) ans="111";
			else ans="110";
			
			if(abs(id1[2]-id2[2])==1&&t1==t2) ans+='1';
			else ans+='0';
			
		}else{
			ans="1000";
		}
	}else{
		ans="0000";
	}
	cout<<ans;
	return 0;
} 
