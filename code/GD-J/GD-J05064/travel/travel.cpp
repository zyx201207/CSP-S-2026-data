#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<0<<0<<0<<0;
		return 0;
	}
	cout<<1;
	int p1=1;
	string t1="";
	string t2="";
	for(int i=0;i<=1;i++){
		t1+=s1[i];
		t2+=s2[i];
	}
	int p2;
	if(t1==t2){
		cout<<1;
		p2=1;
	}else{
		cout<<0;
		p2=0;
	}
	if(p2==0){
		cout<<0<<0;
		return 0;
	}
	if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	int x=s1[2]+0;
	int y=s2[2]+0;
	int m=max(x,y);
	int mi=min(x,y);
	if(m-mi==1){
			cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
