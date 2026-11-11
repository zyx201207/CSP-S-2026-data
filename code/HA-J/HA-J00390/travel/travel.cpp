#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,a1,a2;
	cin>>s1>>a1>>s2>>a2;
	bool flag=0;
	bool qw=0;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i])flag=1;
	}
	if(!flag)cout<<1;
	else cout<<0<<0<<0;
	if(!flag){
		for(int i=0;i<2;i++){
			if(a1[i]!=a2[i]){
				qw=1;
				cout<<0;
				break;
			}
		}
		if(!qw)cout<<1;
		else cout<<0<<0;
		if(!qw)if((a1[2]=='A'&&a2[2]=='B')||(a1[2]=='A'&&a2[2]=='C')||(a1[2]=='B'&&a2[2]=='C')||(a1[2]=='B'&&a2[2]=='A')||(a1[2]=='C'&&a2[2]=='A')||(a1[2]=='C'&&a2[2]=='B')||(a1[2]=='D'&&a2[2]=='F')||(a1[2]=='F'&&a2[2]=='D'))cout<<1;
		
	}
	if(qw)cout<<0;
	else if(((a1[2]=='C'&&a2[2]=='D')||(a1[2]=='D'&&a2[2]=='C'))||abs(a2[2]-a1[2])>=2||a1[2]==a2[2])cout<<0;
	else cout<<1;
	return 0;
}

