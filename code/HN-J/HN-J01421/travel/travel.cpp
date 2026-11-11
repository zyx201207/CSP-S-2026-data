#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int f1=0,f2=0;
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1=="01" || r1=="16"){
		cout<<0000;
		return 0;
	}
	if(x1=="01" || x1=="16"){
		cout<<0000;
		return 0;
	}
	for(int i=0;i<r1.size();i++){
		if(r1[i]!=x1[i]){
			f1=1;
			break;
		} 
	}
	if(f1==0) cout<<1;
	else{
		cout<<"0000";
		return 0;
	} 
	
	if(r2[0]==x2[0] && r2[1]==x2[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	} 
	
	int x=r2[2]-'A'+1,y=x2[2]-'A'+1;
	
	if(r2[2]=='D' && x2[2]!='F'){
		cout<<0;
		f2=1;
	} 
	if(r2[2]=='F' && x2[2]!='D'){
		cout<<0;
		f2=1;
	} 
	if(x2[2]=='D' && r2[2]!='F'){
		cout<<0;
		f2=1;
	} 
	else if(x2[2]=='F' && r2[2]!='D'){
		cout<<0;
		f2=1;
	} 
	else cout<<1;
	
	if(f2=1) {
		cout<<0;
		return 0;
	}
	if(r2[2]=='D' && x2[2]=='F') cout<<1;
	if(r2[2]=='F' && x2[2]=='D') cout<<1;
	if(y-x==1 && x+y!=7) cout<<1;
	else if(x-y==1 && x+y!=7) cout<<1;
	else cout<<0;
	return 0;
} 
