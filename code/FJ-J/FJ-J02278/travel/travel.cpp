#include<bits/stdc++.h>
using namespace std;
#define int long long
bool ans[5];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	bool f=0;
	for(int i=0;i<cr.size();i++){
		if(cr[i]!=cx[i])f=1;
	}
	if(f==0)ans[1]=1;
	f=0;
	for(int i=0;i<2;i++){
		if(sr[i]!=sx[i])f=1;
	}
	if(f==0&&ans[1])ans[2]=1;
	if(ans[2]&&((sr[2]=='A'&&sx[2]=='B'||sr[2]=='A'&&sx[2]=='C'||sr[2]=='B'&&sx[2]=='C'||sr[2]=='D'&&sx[2]=='E')||(sx[2]=='A'&&sr[2]=='B'||sx[2]=='A'&&sr[2]=='C'||sx[2]=='B'&&sr[2]=='C'||sx[2]=='D'&&sr[2]=='E'))){
		ans[3]=1;
		if(sr[2]=='A'&&sx[2]=='B'||sr[2]=='B'&&sx[2]=='C'||sr[2]=='D'&&sx[2]=='E'||sx[2]=='A'&&sr[2]=='B'||sx[2]=='B'&&sr[2]=='C'||sx[2]=='D'&&sr[2]=='E')ans[4]=1;
	}
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	return 0;
}
