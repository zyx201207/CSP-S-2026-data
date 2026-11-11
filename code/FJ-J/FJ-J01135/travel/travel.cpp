#include<bits/stdc++.h>
using namespace std;
string c1,z1,c2,z2;
int cnt1,cnt2;
bool flag=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>z1>>c2>>z2;
	if(c1==c2){
		cout<<1;
		if(z1[0]==z2[0]&&z1[1]==z2[1]){
			cout<<1;
			cnt1=z1[2]-'A'+1;
			cnt2=z2[2]-'A'+1;
			if(cnt1<=3&&cnt2<=3)cout<<1;
			else if(cnt1>=4&&cnt2>=4)cout<<1;
			else{
				cout<<0;
				flag=0;
			}
			if(flag==1){
				if(abs(z1[2]-z2[2])==1||(z1[2]==4&&z2[2]==6)||(z1[2]==6&&z2[2]==4))cout<<1;
				else cout<<0;
			}else cout<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	return 0;
}
