#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c2;
	string s1,s2,s3,s4; cin>>c1>>s1>>c2>>s2;
	bool x=0;
	char a=s1[2],b=s2[2];
	
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if(a+b<='A'+'C' || a+b=='E'+'F') cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(a+1==b || b+1==a) cout<<"1";
	else cout<<"0";
	return 0;
}