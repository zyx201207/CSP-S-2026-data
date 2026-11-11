#include<bits/stdc++.h> 
using namespace std;
#define int long long 
signed main(){
	int a1=0,a2=0,a3=0;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s_1,c_1,s_2,c_2;
	cin>>s_1>>c_1>>s_2>>c_2;
	for(int i=0;i<=1;i++){
		if(s_1[i]==s_2[i]){
			a1++;
		}
		if(c_1[i]==c_2[i]){
			a2++;
		}
	}
	if(a1==2) cout<<1;
	else{
		cout<<"0000";
		return 0;	
	} 
	if(a2==2) cout<<1;
	else cout<<0;
	if(a2==2){
		if(c_1[2]-c_2[2]==1&&c_1[2]=='D')cout<<0;
		else if(c_2[2]-c_1[2]==1&&c_2[2]=='D') cout<<0;
		else cout<<1;
	} 
	else cout<<0;
	if(a2==2){
		if(c_1[2]-c_2[2]==1 && (c_1[2]!='C' && c_2[2]!='D')){
			cout<<1;
		}
		else if(c_2[2]-c_1[2]==1 && (c_1[2]!='C' && c_2[2]!='D')){
			cout<<1;
		}
		else if((c_2[2]=='D'&&c_1[2]=='F') || (c_2[2]=='F' && c_1[2]=='D')){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	
	
}
