#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000\n";
	}else{
		cout<<"1";
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			cout<<"000\n";
		}else{
			cout<<"1";
			if((s1[2]<='C')!=(s2[2]<='C')){
				cout<<"00\n";
			}else{
				cout<<"1";
				if(abs(s1[2]-s2[2])!=1){
					cout<<"0\n";
				}else{
					cout<<"1\n";
				}
			}
		}
	}
	return 0;
}
/*
xiang shang ren lei mi huo xing wei da shang
kuai lai ting "let you down" 

try so hard to release
you are out of the misery
hold on to your wishes
if you can't hold on to me

forgive me for letting you down
forgive me for letting you down
i guess i'm not strong enough
right now

oh my love
	letting you down
my love 
	letting you down
*/
