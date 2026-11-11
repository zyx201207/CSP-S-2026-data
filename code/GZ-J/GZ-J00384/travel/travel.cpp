//GZ-J00384 Îºð©éª
#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>a>>b>>c>>d;
	if(a==c) printf("%d",1);
	else{
		printf("%d%d%d%d",0,0,0,0);
		return 0;
	}

	if(b[0]==d[0] && b[1]==d[1]) printf("%d",1);
	else printf("%d",0);

	if((b[2]<'D' && (d[2]!='D' && d[2]!='F')) || (b[2]=='D' && d[2]=='F')) printf("%d",1);
	else printf("%d",0);

	if(b[2]=='D' && d[2]=='F'){
		printf("%d",1);
		return 0;
	}
	if((b[2]+1==d[2] && b[2]!='C') || (b[2]-1==d[2] && b[2]!='D')) printf("%d",1);
	else printf("%d",0);

	return 0;
}
