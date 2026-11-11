#include<bits/stdc++.h>
using namespace std;
//#define int long long
string c_1,c_2,s_1,s_2;
bool ans[4];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		ans[0]=1;
		if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]){
			ans[1]=1;
			if(s_1>s_2)swap(s_1,s_2);
			if(s_1[2]<='C'&&s_2[2]<='C'||s_1[2]>='D'&&s_2[2]>='D'){
				ans[2]=ans[3]=1;
				if(s_1[2]=='A'&&s_2[2]=='C')ans[3]=0;
			}
		}
	}
	for(int i=0;i<4;i++)cout<<((int)ans[i]);
	return 0;
}
