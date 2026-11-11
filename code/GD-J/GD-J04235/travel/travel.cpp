#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1,s2;int c1,s11,s22,c2;
	cin>>c1>>s11>>s1>>c2>>s22>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
//		cerr<<s11<<' '<<s1<<' '<<s22<<' '<<s2;
		if(s11==s22){
			cout<<1;
		}
		else{
			cout<<"000";
			return 0;
			
		}
		if(s1=='F'&&s2=='D'||s1=='D'&&s2=='F'||s1=='A'&&s2!='D'&&s2!='F'||s1=='B'&&s2!='D'&&s2!='F'||s1=='C'&&s2!='D'&&s2!='F'){
			cout<<1;
		}
		else{
			cout<<"00";return 0;
		}
		if(s1=='F'&&s2=='D'||s1=='D'&&s2=='F'||s1=='A'&&s2=='B'||s1=='B'&&s2=='A'||s1=='B'&&s2=='C'||s1=='C'&&s2=='B'){
			cout<<1;
		}
		else{
			cout<<0;return 0;
		}
	}
	return 0;
}
