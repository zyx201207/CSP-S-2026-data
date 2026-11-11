#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,shu1,shu0;
int cnt,ans,he,len,p,q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cnt=c1[0]-'0';
	cnt=cnt*10;
	cnt+=c1[1]-'0';
	ans=c2[0]-'0';
	ans=ans*10;
	ans+=c2[1]-'0';
	he=s1[2]-'A'+1;
	len=s2[2]-'A'+1;
	p=s1[0]-'0';
	p=p*10;
	p+=s1[1]-'0';
	q=s2[0]-'0';
	q=q*10;
	q+=s2[1]-'0';
	shu1='1';
	shu0='0';
	if(he>5){
		he=5;
	}
	if(len>5){
		len=5;
	}
	if(cnt==ans){
		cout<<shu1;
		if(p==q){
			cout<<shu1;
			if(he>=4&&len>=4){
				cout<<shu1;
				if(he+len==3||he+len==5||he+cnt==9){
					cout<<shu1;
				}else{
					cout<<shu0;
				}
			}else if(he<4&&len<4){
				cout<<shu1;
				if(he+len==3||he+len==5||he+cnt==9){
					cout<<shu1;
				}else{
					cout<<shu0;
				}
			}else{
				cout<<shu0<<shu0;
			}
		}else{
			cout<<shu0<<shu0<<shu0;
		}
	}else{
		cout<<shu0<<shu0<<shu0<<shu0;
	}
	return 0;
}
