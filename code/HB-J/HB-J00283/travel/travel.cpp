#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a,b,c;
	int ca,cb,pa,pb,wa,wb;
	cin>>a>>b;
	ca=(a-48)*10+b-48;
	cin>>a>>b>>c;
	pa=(a-48)*10+b-48,wa=c;
	cin>>a>>b;
	cb=(a-48)*10+b-48;
	cin>>a>>b>>c;
	pb=(a-48)*10+b-48,wb=c;
	if(ca==cb) cout<<1;
	else cout<<0;
	if(ca==cb&&pa==pb) cout<<1;
	else cout<<0;
	if(ca==cb&&pa==pb&&((wa<='C'&&wb<='C')||(wa>'C'&&wb>'C'))) cout<<1;
	else cout<<0;
	if(ca==cb&&pa==pb&&abs(wa-wb)==1&&(!((wa=='C'&&wb=='D')||(wa=='D'&&wb=='C')))) cout<<1;
	else cout<<0;
	return 0;
}
