//GZ-J00173  遵义航天高级中学  刘鑫馨
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	bool f=true;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
		f=false;
	}
	
	string a,b;
	
	for(int i=0;i<3;i++){
		a[i]=s1[i];
		b[i]=s2[i];
	}
	bool j=true;
	if(f){
		if(a==b){
			cout<<"1";
		}else{
			cout<<"0";
			j=false;
		}
		if((s1[2]=='A'&&s2[2]=='B')  ||  (s1[2]=='B'&&s2[2]=='C')  ||  (s1[2]=='D'&&s2[2]=='F')  ||(s1[2]=='B'&&s2[2]=='A')  || (s1[2]=='C'&&s2[2]=='B') || (s1[2]=='F'&&s2[2]=='D') || (s1[2]=='A'&&s2[2]=='C') || (s1[2]=='C'&&s2[2]=='A')){
			cout<<"1";
		}else{
			cout<<"0";	
		}
		if((s1[2]=='A'&&s2[2]=='B')  ||  (s1[2]=='B'&&s2[2]=='C')  ||  (s1[2]=='D'&&s2[2]=='F')  ||(s1[2]=='B'&&s2[2]=='A')  || (s1[2]=='C'&&s2[2]=='B') || (s1[2]=='F'&&s2[2]=='D')){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
		
		
	}else{
		cout<<"000";
	}
	
	return 0;
} 
