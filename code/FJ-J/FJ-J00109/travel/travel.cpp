#include<bits/stdc++.h>
using namespace std;
int main(){
 	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
 	char a,b,c,d,e,f,g,h,i,j;
 	int aa,bb,cc,dd;
 	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
 	aa=(a-'0')*10+(b-'0');
	bb=(c-'0')*10+(d-'0');
	cc=(f-'0')*10+(g-'0');
	dd=(h-'0')*10+(i-'0');
	if(aa==cc) cout<<1;
	else cout<<0;
	if(aa==cc&&bb==dd) cout<<1;
	else cout<<0;
	if(aa==cc&&bb==dd&&((e=='A'&&j=='B')||(e=='B'&&j=='A')||(e=='A'&&j=='C')||(e=='C'&&j=='A')||(e=='B'&&j=='C')||(e=='C'&&j=='B')||(e=='D'&&j=='F')||(e=='F'&&j=='D'))) cout<<1;
	else cout<<0;
	if(aa==cc&&bb==dd&&((e=='A'&&j=='B')||(e=='B'&&j=='A')||(e=='B'&&j=='C')||(e=='C'&&j=='B')||(e=='D'&&j=='F')||(e=='F'&&j=='D'))) cout<<1;
	else cout<<0;
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 }
