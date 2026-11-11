//GZ-J00466 遵义市第十九中学 吴国懋
#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rzx,xzx,rp,xp;
	bool pd=1;
	cin>>rzx>>rp>>xzx>>xp;
	for(int i=0; i<rzx.size(); i++) {
		if(rzx[i]!=xzx[i]) {
			pd=0;
			break;
		}
	}
	if(pd==1) cout<<1;
	if(pd==0) cout<<0<<0<<0<<0;
	if(pd==1) {
		for(int i=0; i<rp.size()-1; i++) {
			if(rp[i]!=xp[i]) {
				pd=0;
				break;
			}
		}
		if(pd==1)cout<<1;
		if(pd==0)cout<<0<<0<<0;
		if(pd==1) {
			if((rp[2]=='A'&&xp[2]=='B')||(rp[2]=='A'&&xp[2]=='C')||(rp[2]=='B'&&xp[2]=='C')||(rp[2]=='B'&&xp[2]=='A')||(rp[2]=='B'&&xp[2]=='C')||(rp[2]=='C'&&xp[2]=='A')||(rp[2]=='C'&&xp[2]=='B')||(rp[2]=='D'&&xp[2]=='F')||(rp[2]=='F'&&xp[2]=='D')) {
				cout<<1;
				int rasc=rp[2],xasc=xp[2];
				if(rasc==xasc-1||rasc==xasc+1) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
			
		}

	}
	return 0;
}
