#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,s1,s2,ans,s_1,s_2;
	int a,b;
	cin>>c1>>s1>>c2>>s2;
	s_1=s1[0]+s1[1];
	s_2=s2[0]+s2[1];
	
	
	if(c1==c2){
		ans[0]='1';
		a=1;
	}else{
		ans[0]='0';
		a=0;
	}
	if(s_1==s_2){
		if(a){
			ans[1]='1';
			b=1;
		}else{
			ans[1]='0';
			b=0;
		}	
	}else{
		if(a){
			ans[1]='1';
			b=1;	
		}else{
			ans[1]='0';
			b=0;
		}
	}
	if(s1[2]>='A' && s1[2]<='C'){
		if(s2[2]>='A' && s2[2]<='C'){
			if(a && b){
				ans[2]='1';
			}else{
				ans[2]='0';
			}
		}else{
			ans[2]='0';
		}
	}else{
		if(s2[2]>='D' && s2[2]<='F'){
			if(a && b){
				ans[2]='1';
			}else{
				ans[2]='0';
			}
		}else{
			ans[2]='0';
		}
	}
	if(s1[2]+1==s2[2] || s1[2]-1==s2[2]){
		if(s1[2]=='C' && s2[2]=='D'){
			ans[3]='0';
		}else if(s2[2]=='C' && s1[2]=='D'){
			ans[3]='0';
		}else{
			if(a && b){
				ans[3]='1';
			}else{
				ans[3]='0';
			}
		} 
	}else{
		ans[3]='0';
	}
	
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	
	return 0;
}
