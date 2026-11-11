#include<bits/stdc++.h>
using namespace std;
int ai,bi,qi,aj,bj,qj;
string ci,si,cj,sj;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ci>>si>>cj>>sj;
	if (ci[0]=='0') ai=ci[1]-'0';
	else ai=ci[1]-'0'+10;
	if (cj[0]=='0') aj=cj[1]-'0';
	else aj=cj[1]-'0'+10;
	
	if (si[0]=='0') bi=si[1]-'0';
	else bi=si[1]-'0'+10;
	if (sj[0]=='0') bj=sj[1]-'0';
	else bj=sj[1]-'0'+10;
	
	qi=si[2]-'A'+1;
	qj=sj[2]-'A'+1;
	
	if (ai==aj) {
		cout<<1;
		if (bi==bj){
			cout<<1;
			if (((1<=qi&&qi<=3)&&(1<=qj&&qj<=3))||((5<=qi&&qi<=6)&&(5<=qj&&qj<=6))) {
				cout<<1;
				if (qi-qj==1||qj-qi==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
