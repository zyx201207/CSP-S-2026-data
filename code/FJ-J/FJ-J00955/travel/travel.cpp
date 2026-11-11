#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int cnt=(s1[0]-'0')*10+(s1[1]-'0');
		int sum=(s2[0]-'0')*10+(s2[1]-'0');
		if(cnt==sum){
			cout<<"1";
			char ch1=min(s1[2],s2[2]),ch2=max(s1[2],s2[2]);
			if((ch1=='D'&&ch2=='F')||('A'<=ch1&&ch2<='C')){
				cout<<"1";
				if(ch2-ch1==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
