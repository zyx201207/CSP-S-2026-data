#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	int c3=(c2[0]-'0')*10+c2[1]-'0';
	int s3=(s2[0]-'0')*10+s2[1]-'0';
	if(c1==s1){
		cout<<1;
		if(c3==s3){
			cout<<1;
			if(c2[2]>s2[2]){
				swap(c2[2],s2[2]);
			}
			if(c2[2]>='A'&&c2[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
				cout<<1;
				if(s2[2]-c2[2]==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(c2[2]>='D'&&c2[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
				cout<<"11";
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
