#include<bits/stdc++.h>
using namespace std;
#define int long long
int s[4];
struct ly{
	string cx;
	string zy;
}aa,ba;
string ab,bb;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> aa.cx >> aa.zy >> ba.cx >> ba.zy;
	ab=aa.zy[0]+aa.zy[1];
	bb=ba.zy[0]+ba.zy[1];
	if (aa.cx==ba.cx){
		s[0]=1;
		if (ab==bb){
			s[1]=1;
			if ((aa.zy[2]=='D'&&ba.zy[2]=='F')||(aa.zy[2]=='F'&&ba.zy[2]=='F')){
				s[2]=1;
				s[3]=1;
			}
			if ((aa.zy[2]!='D'&&aa.zy[2]!='F')&&(ba.zy[2]!='D'&&ba.zy[2]!='F')){
				s[2]=1;
				if ((!aa.zy[2]=='A'&&ba.zy[2]=='C')||(!aa.zy[2]=='C'&&ba.zy[2]=='A')){
					s[3]=1;
				}
			}
		}
	}
	cout << s[0] << s[1] << s[2] << s[3];
}
