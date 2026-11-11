#include<bits/stdc++.h>
using namespace std;
string cn1,cn2,sn1,sn2;
bool f1,f2,f3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cn1>>sn1>>cn2>>sn2;
	if(cn1==cn2) {
		cout<<1;
		f1=1;
	}
	else cout<<0;
	if(f1==1 && sn1[0]==sn2[0] && sn1[1]==sn2[1]) {
		cout<<1;
		f2=1;
	}
	else cout<<0;
	if(sn1[2]<'D' && sn2[2]<'D' && f1==1 && f2==1 || sn1[2]>='D' && sn2[2]>='D' && f1==1 && f2==1) {
		cout<<1;
		f3=1;
	}
	else cout<<0;
	if(sn1[2]==char(sn2[2]+1) && f1==1 && f2==1 && f3==1 || char(sn1[2]+1)==sn2[2] && f1==1 && f2==1 && f3==1) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
