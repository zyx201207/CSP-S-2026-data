#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ans=0,z1=0,z2=0;
	string c1,s1,c2,s2;
	for(int i=0;i<=3;i++){
		if(c1[i]==c2[i]) ans=1;
		else ans =0;
	}
	if(ans==1) cout<<ans;
	if(ans==0) {
		cout<<0000;
		return 0000;
		}
//
	for(int i=0;i<=1;i++){
		if(s1[i]==s2[i]) ans=1;
		else ans =0;
	}
	if(ans==1) cout<<ans;
	if(ans==0) {
		cout<<000;
		return 000;
		}
//
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') z1=1;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') z2=1;
	if(z1==z2) ans=1;
	if(z1!=z2) ans=0;
	if(ans==1) cout<<ans;
	if(ans==0) {
		cout<<00;
		return 00;
		}
//
	if(s1[2]-1==s2[2]||s1[2]+1==s2[2]||z1==z2==0) ans=1;
	else ans==0;
	cout<<ans;
	return 0;
}
