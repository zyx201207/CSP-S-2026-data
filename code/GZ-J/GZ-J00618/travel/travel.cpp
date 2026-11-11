//GZ-J00618,北京师范大学贵阳附属中学，余昊锴
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a1,b,b1;
	cin>>a>>a1>>b>>b1;
	if(a[1]==b[1]){
		cout<<"1";
		if(a1[1]==b1[1]){
			cout<<"1";
			if(a1[2]<'D'&&b1[2]<'D'||a1[2]>='D'&&b1[2]>='D'){
				cout<<"1";
				if(a1[2]+1==b1[2]||a1[2]-1==b1[2]) cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
