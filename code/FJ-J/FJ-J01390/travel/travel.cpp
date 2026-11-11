#include<bits/stdc++.h>
using namespace std;
string p[2],q[2];
int a[3],b[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++)cin>>p[i];
	for(int i=0;i<2;i++)cin>>q[i];
	a[0]=10*(p[0][1]-'0')+(p[0][0]-'0');
	a[1]=10*(p[1][1]-'0')+(p[1][0]-'0');
	a[2]=(p[1][2]=='F'?5:p[1][2]-'A'+1);
	b[0]=10*(q[0][1]-'0')+(q[0][0]-'0');
	b[1]=10*(q[1][1]-'0')+(q[1][0]-'0');
	b[2]=(q[1][2]=='F'?5:q[1][2]-'A'+1);
	if(a[0]==b[0]){
		cout<<"1";
		if(a[1]==b[1]){
			cout<<"1";
			if((a[2]<=3&&b[2]<=3)||(a[2]>3&&b[2]>3)){
				cout<<"1";
				if(abs(a[2]-b[2])==1)cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
