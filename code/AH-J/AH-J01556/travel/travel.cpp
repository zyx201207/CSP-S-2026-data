#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int c11=0,c22=0;
	for(int i=0;i<=1;i++){
		if(c1[i]!=0){
			c11=c11*10+(c1[i]-'0');
			
		}
		if(c2[i]!=0){
			c22=c22*10+(c2[i]-'0');
		}
	}
	if(c11==c22){
		cout<<1;
		int s11=0,s22=0;
		for(int i=0;i<=1;i++){
			if(s1[i]!=0){
			s11=s11*10+(s1[i]-'0');
			
			}
			if(s2[i]!=0){
				s22=s22*10+(s2[i]-'0');
			}
		}
		if(s22==s11){
			cout<<1;
			int x=s1[2]-'A',y=s2[2]-'A';
			int cnt=0;
			if(x==1||x==2||x==0){
				if(y==1||y==2||y==0){
					cnt=1;
				}
			}
			if(x==3||x==4){
				if(y==3||y==4){
					cnt=1;
				}
			}
			if(cnt==1){
				cout<<1;
				if(x-y<=1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
			
		}
	
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
	
}
