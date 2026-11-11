#include<bits/stdc++.h> 
using namespace std;
char a,s;
int q,w,e,r,t,y,u,i;
int main(){ 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>q>>w>>a>>e>>r>>s;
	if(q==e) cout<<"1";
	else cout<<"0";
	if(q==e && w==r) cout<<"1";
	else cout<<"0";
	if(q==e && a=='A' && s=='B' || s=='C') cout<<"1";
	else if(w==r && q==e && a=='B' && s=='A' || s=='C') cout<<"1";
	else if(w==r && q==e && a=='C' && s=='A' || s=='B') cout<<"1";
	else if(w==r && q==e && a=='D' && s=='F') cout<<"1";
	else if(w==r && q==e && a=='F' && s=='D') cout<<"1";
	else cout<<"0";
	if(w==r && q==e && a=='A' && s=='B') cout<<"1";
	else if(w==r && q==e && a=='B' && s=='A' || s=='C') cout<<"1";
	else if(w==r && q==e && a=='C' && s=='B' ) cout<<"1";
	else if(w==r && q==e && a=='D' && s=='F') cout<<"1";
	else if(w==r && q==e && a=='F' && s=='D') cout<<"1";
	else cout<<"0";
	return 0;
}
