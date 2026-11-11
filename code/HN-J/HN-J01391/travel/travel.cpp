#include<bits/stdc++.h>
using namespace std;//Trick||Treat! travel
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			cout<<0<<0<<0;
			return 0;
		}
	}
	cout<<1;
	if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]=='D'||s2[2]=='F'){
			cout<<1<<1;
			return 0;
		}else{
			cout<<0<<0;
			return 0;
		}
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			cout<<1;
		}else{
			cout<<0<<0;
			return 0;
		}
	}
	if(abs(int(s1[2])-int(s2[2]))==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
