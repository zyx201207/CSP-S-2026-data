#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// LG CodingLoverRao29(1470495), I have come here.
// Trick||Treat!
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			char se1=s1[2],se2=s2[2];
			if(se1<='C' && se2<='C'){
				cout<<1;
				if(se1=='B'||se2=='B'){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(se1>='D' && se2>='D'){
				cout<<"11";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
}
/*
#include<bits/stdc++.h>
#define linestart {
#define lineend }
#define over ;
#define zfkh [
#define yfkh ]
#define zkh (
#define ykh )
#define cinin >>
#define coutout <<
#define dh ,
#define dengyu ==
#define dydy >=
#define xydy <=
#define fuzhi =
#define mhmh ::
#define dot .
using namespace std over
using ll fuzhi long long over
string c1 dh s1 dh c2 dh s2 over
int main zkh ykh linestart
	freopen zkh "travel.in" dh "r" dh stdin ykh over
	freopen zkh "travel.out" dh "w" dh stdout ykh over
	ios mhmh sync_with_stdio zkh 0 ykh over
	cin dot tie zkh 0 ykh over
	cin cinin c1 cinin s1 cinin c2 cinin s2 over
	if zkh c1 zfkh 0 yfkh dengyu c2 zfkh 0 yfkh and c1 zfkh 1 yfkh dengyu c2 zfkh 1 yfkh  ykh linestart
		cout coutout 1 over
		if zkh s1 zfkh 0 yfkh dengyu s2 zfkh 0 yfkh and s1 zfkh 1 yfkh dengyu s2 zfkh 1 yfkh  ykh linestart
			cout coutout 1 over
			char se1 fuzhi s1 zfkh 2 yfkh dh se2 fuzhi s2 zfkh 2 yfkh over
			if zkh se1 xydy 'C' and se2 xydy 'C' ykh linestart
				cout coutout 1 over
				if zkh se1 dengyu 'B' or se2 dengyu 'B' ykh linestart
					cout coutout 1 over
				lineend
				else linestart
					cout coutout 0 over
				lineend
			lineend
			else if zkh se1 dydy 'D' and se2 dydy 'D' ykh linestart
				cout coutout "11" over
			lineend
			else linestart
				cout coutout "00" over
			lineend
		lineend
		else linestart
			cout coutout "000" over
		lineend
	lineend
	else linestart
		cout coutout "0000" over
	lineend
lineend
*/








































//

