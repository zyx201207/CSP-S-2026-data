#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,cnt1,cnt2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	cnt1=s1[2]-'A';
	cnt2=s2[2]-'A';
	if(cnt1==3) cnt1=4;
	if(cnt2==3) cnt2=4;
	if(cnt2>cnt1) swap(cnt1,cnt2);
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}else{
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			cout<<"1000"<<endl;
			return 0;
		}else{
			if(cnt1>3&&cnt2<3||cnt1<3&&cnt2>3){
				cout<<"1100"<<endl;
				return 0;
			}else{
				if(cnt2==4||cnt1-cnt2==1) cout<<"1111"<<endl;
				else cout<<"1110"<<endl;
			}
		}
	}
	return 0;
}
