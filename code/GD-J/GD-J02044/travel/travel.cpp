#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	long long k=0,k1=0,k2=0;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.length();i++){
		if(c1[i]!=c2[i]) k=1;
	}
	if(k==0){
		cout<<"1";
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]) k=1;
		}
		if(k==0){
			cout<<"1";
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') k1=1;
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') k2=1;
			if(k1==k2){
				cout<<"1";
				if(k1==0) cout<<"1";
				else if(s1[2]=='B'||s2[2]=='B') cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
