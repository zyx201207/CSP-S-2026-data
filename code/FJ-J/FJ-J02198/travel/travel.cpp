#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	string pid1="",pid2="";
	for(int i=0;i<2;i++){
		pid1+=c2[i];
		pid2+=s2[i];
	}
	if(c1==s1) cout<<1;
	else cout<<0;
	if(c1==s1&&pid1==pid2) cout<<1;
	else cout<<0;
	if(c1==s1&&pid1==pid2&&((c2[2]<='C'&&s2[2]<='C')||(c2[2]>='D'&&s2[2]>='D'))) cout<<1;
	else cout<<0;
	if(c1==s1&&pid1==pid2&&((c2[2]<='C'&&s2[2]<='C')||(c2[2]>='D'&&s2[2]>='D'))&&abs((int)s2[2]-(int)c2[2])==1) cout<<1;
	else cout<<0;
	return 0;
}
