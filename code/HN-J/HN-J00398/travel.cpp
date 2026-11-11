#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[1001]={'A','B','C'};
	char b[1001]={'D','E','F'};
	int a1=0,a2=0,b1=0,b2=0;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]==c2[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<3;i++){
		
		if(s1[2]==a[i]){
			a1=1;
			b1=i;
		}
	}
	for(int i=0;i<3;i++){
		if(s2[2]==a[i]){
			a2=1;
			b2=i;
		}
	}
	if(a1==a2){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(b1+1==b2||b1-1==b2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	return 0;
} 
