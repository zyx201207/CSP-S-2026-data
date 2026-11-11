#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cc,ss,cc2,ss2;
	cin>>cc>>ss>>cc2>>ss2;
	if(cc==cc2){cout<<1;
	
	if(ss[0]==ss2[0]&&ss[1]==ss2[1]){
		cout<<1;
		if(((ss[2]=='A'||ss[2]=='B'||ss[2]=='C')&&(ss2[2]=='A'||ss2[2]=='B'||ss2[2]=='C'))||((ss[2]=='D'||ss[2]=='F')&&(ss2[2]=='D'||ss2[2]=='F'))){
			cout<<1;
			//cout<<' '<<ss[2]+0<<' '<<ss2[2]+0;
		if(ss[2]+0==ss2[2]+1||ss[2]+0==ss2[2]-1)cout<<1;
		else cout<<0;
			}
		else cout<<0<<0;
		
		
		}
	else cout<<0<<0<<0;}
	

else cout<<0<<0<<0<<0;
return 0;
}
