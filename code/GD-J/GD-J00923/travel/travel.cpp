#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	string c_1,s_1,c_2,s_2;
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		cout<<"1";
		if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]){
			cout<<"1";
			if((s_1[2]>='A'&&s_1[2]<='C'&&s_2[2]>='A'&&s_2[2]<='C')||(s_1[2]>='D'&&s_1[2]<='F'&&s_2[2]>='D'&&s_2[2]<='F')){
				cout<<"1";
				if(abs(s_1[2]-s_2[2])==1){
					cout<<"1";
				}
				else{
					cout<<"0";
					return;
				}
			}
			else{
				cout<<"00";
				return;
			}
		} 
		else{
			cout<<"000";
			return;
		}
	} 
	else{
		cout<<"0000";
		return ;
	}
	
} 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	} 
}
