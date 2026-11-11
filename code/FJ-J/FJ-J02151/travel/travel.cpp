#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[3]={'A','B','C'};
	char b[2]={'D','E'};
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}else{
		cout<<"1";
		if(s1[1]=s2[1] && s1[0]==s2[0]){
			cout<<"1";
		}else{
			cout<<"000";
			return 0;
		}
		if(((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')) || ((s1[2]=='D' || s1[2]=='E') && (s2[2]=='D' || s2[2]=='E'))){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
		if(s1[2]-s2[2]==1 || s1[2]-s2[2]==-1){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	
	return 0;
}
