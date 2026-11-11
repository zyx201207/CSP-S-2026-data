#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int cr1=(c1[0]-'0')*10+c1[1]-'0',cr2=(c2[0]-'0')*10+c2[1]-'0',sr1=(s1[0]-'0')*10+s1[1]-'0',sr2=(s2[0]-'0')*10+s2[1]-'0';
	char k1=s1[2],k2=s2[2];
	if(cr1==cr2){
		cout<<1;
		if(sr1==sr2){
			cout<<1;
			if(((k1=='A'||k1=='B'||k1=='C')&&(k2=='A'||k2=='B'||k2=='C'))||((k1=='F'||k1=='D')&&(k2=='D'||k2=='F'))){
				cout<<1;
				if(abs(k1-k2)==1)cout<<1;
				else cout<<0;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	return 0;
}
