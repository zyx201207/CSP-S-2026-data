#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[5],s2[5];
	cin>>c1>>s1>>c2>>s2;
	int a1=s1[2],a2=s2[2];
	if(c1==c2) {
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(a1<='C'&&a2<='C') {
				cout<<1;
				if(abs(a1-a2)<2) cout<<1;
				else cout<<0;
			}
			else if(a1>='D'&&a2>='D') {
				cout<<1;
				if(abs(a1-a2)<2) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		} 
		else {
			cout<<0<<0<<0;
			return 0;
		}
	}
	else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
}
