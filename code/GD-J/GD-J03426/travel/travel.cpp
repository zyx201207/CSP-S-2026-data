#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string wei1="";
		string wei2="";
		for(int i=0;i<2;i++)wei1+=s1[i],wei2+=s2[i];
		if(wei1==wei2){
			cout<<1;
			char zuo1=s1[2];
			char zuo2=s2[2];
			if(((zuo1=='A'||zuo1=='B'||zuo1=='C')&&(zuo2=='A'||zuo2=='B'||zuo2=='C')) || ((zuo1=='D'||zuo1=='F')&&(zuo2=='D'||zuo2=='F'))){
				cout<<1;
				if((zuo1=='D'||zuo1=='F')&&(zuo2=='D'||zuo2=='F'))cout<<1;
				else if(zuo1+1==zuo2||zuo1-1==zuo2)cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
