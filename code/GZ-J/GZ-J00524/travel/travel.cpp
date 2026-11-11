//GZ-J00524 兴义市弘毅中学 卢浩宇 
#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int cnt=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else {
	cout<<0<<0<<0<<0;
	return 0;
}
	while(cnt<2){
       if(s1[cnt]!=s2[cnt]){
       	cout<<0<<0<<0;
       	return 0;
	   }
	else if(cnt==1) {
		cout<<1;
		break;
	}
	   cnt++;
	}
		if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C')) {
			cout<<1;
		}
		else{
			cout<<0<<0;
			return 0;
		}
		if((s1[2]=='A'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='C')) cout<<0;
		else cout<<1;
	return 0;
} 
