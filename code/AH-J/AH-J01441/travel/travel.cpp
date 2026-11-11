#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<'1';
			int zw1=s1[2]-'A',zw2=s2[2]-'A';
			if(zw1>zw2) swap(zw1,zw2);
			if(zw1==3&&zw2==5) cout<<"11"<<endl;
			else if(zw1==0&&zw2==1) cout<<"11"<<endl;
			else if(zw1==1&&zw2==2) cout<<"11"<<endl;
			else if(zw1==0&&zw2==2) cout<<"10"<<endl;
			else cout<<"00"<<endl;
		}else cout<<"000"<<endl;
	}else cout<<"0000"<<endl;
	return 0;
}
