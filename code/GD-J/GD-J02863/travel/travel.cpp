#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int kk=0;
	if(c1==c2){
		cout<<1;
		kk=1;
	}
	else cout<<0;
	if(kk==0){
		cout<<"000";
		return 0;
	}
	
	
	int k=0;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]) k=1;
	}
	if(k==0) cout<<1;
	else cout<<0;
	int p=0;
	if(k==1){
		cout<<"00";
		return 0;
	}
	else{
		if((s1[2]<'D' && s2[2]<'D') || (s1[2]>'C' && s2[2]>'C')){
			p=1;
			cout<<1;
		}
		else cout<<0;	
	}
	
	if(!p) cout<<0;
	else{
		if(abs(s1[2]-s2[2])==1 || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
