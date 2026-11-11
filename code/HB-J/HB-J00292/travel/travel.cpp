#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
int ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc){
		ans[1]=1;
		if(rs[0]==xs[0]&&rs[1]==xs[1]){
			ans[2]=1;
			if(!(((rs[2]=='D'||rs[2]=='F')&&(xs[2]=='A'||xs[2]=='B'||xs[2]=='C'))||((xs[2]=='D'||xs[2]=='F')&&(rs[2]=='A'||rs[2]=='B'||rs[2]=='C')))){
				ans[3]=1;
				if((abs(rs[2]-xs[2])==1)&&(!((rs[2]=='C'&&xs[2]=='D')||(xs[2]=='C'&&rs[2]=='D')))){
					ans[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	return 0;
}
