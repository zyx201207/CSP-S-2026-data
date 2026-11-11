#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	s=s1[0]+s1[1],c=s2[0]+s2[1];
	if(s!=c){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(!((s1[2]>='D' && s2[2]>='D') || (s1[2]<'D' && s2[2]<'D'))){
		cout<<"00";
		return 0;
	}
	cout<<1;
	int a=s1[2],b=s2[2];
	if(a-b==1 || b-a==1) cout<<1;
	else cout<<0;
	return 0;
}
