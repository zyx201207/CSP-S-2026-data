#include<bits/stdc++.h>
using namespace std;
bool cmp(long long qwert,long long b){
	return qwert>b;
}//´óµ½Ð¡£¬µ¹Ðò 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long rcxh,xcxh;
	string rzwh,xzwh;
	cin>>rcxh>>rzwh>>xcxh>>xzwh;
	if(rcxh==xcxh){
		if(rzwh[0]=xzwh[0]&&rzwh[1]==xzwh[1]){
			if((rzwh[2]>'c'&&xzwh[2]>'c')||(rzwh[2]<='c'&&xzwh[2]<='c')){
				if(abs(rzwh[2]-xzwh[2])==1){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else {
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
