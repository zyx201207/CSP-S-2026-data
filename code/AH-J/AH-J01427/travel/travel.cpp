#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c,cc,s,ss;
	cin>>c>>s>>cc>>ss;
	bool pf=0;
	if(c==cc) cout<<1,pf=1;
	else cout<<0;
	int s_shu=(s[0]-'0')*10+(s[1]-'0'),ss_shu=(ss[0]-'0')*10+(ss[1]-'0');
	int s_cha=(s[2]-'A'+1),ss_cha=(ss[2]-'A'+1);
	if(s_shu==ss_shu&&pf==1) cout<<1;
	else cout<<0;
	bool p=0;
	if(s_shu==ss_shu&&pf==1){
		if(s_cha<=3){
			if(ss_cha<=3){
				cout<<1;p=1;
			}
			else cout<<0;
		}
		else{
			if(ss_cha>3){
				cout<<1;p=1;
			}
			else cout<<0;
		}
	}
	else cout<<0;
	if(p==1&&pf==1){
		if(ss_cha+1==s_cha||ss_cha-1==s_cha){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	return 0;
}

