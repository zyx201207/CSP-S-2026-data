#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(j);i<=(k);++i)
#define dwn(i,j,k) for(int i=(j);i>=(k);--i)
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1==c2);
	else return cout<<"0000\n",0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]);
	else return cout<<"1000\n",0;
	char fi=s1[2],se=s2[2];
	if((fi=='A'||fi=='B'||fi=='C')&&(se=='A'||se=='B'||se=='C')||(fi=='D'||fi=='F')&&(se=='D'||se=='F'));
	else return cout<<"1100\n",0;
	if(fi=='A'&&se=='B'||fi=='B'&&se=='C'||fi=='D'&&se=='F')return cout<<"1111\n",0;
	else return cout<<"1110\n",0;
	return 0;
}
