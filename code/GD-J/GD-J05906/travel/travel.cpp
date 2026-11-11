#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1="",s1="",c2="",s2="";
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else {
		cout<<1;
		for(int i=0;i<2;++i){
			if(s1[i]!=s2[i]){
				cout<<"000";
				return 0;
			}
		} 
		cout<<1;
		char a1=s1[2],a2=s2[2];
		if((a1=='A'||a1=='B'||a1=='C')&&(a2=='A'||a2=='B'||a2=='C')&&a1!=a2)
		    cout<<1;
		else if((a1=='D'||a1=='F')&&(a2=='D'||a2=='F')&&a1!=a2)
			cout<<1;
		else{
			cout<<"00";
			return 0;
		}
		int flag=(int)a1-(int)a2;
		if(flag==1||flag==-1)
		cout<<1;
		else 
		cout<<0;	    
	}
} 
