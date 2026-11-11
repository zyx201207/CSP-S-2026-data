#include<bits/stdc++.h>
using namespace std;
namespace FZT{
typedef long long ll;
string c1,s1,c2,s2;
string ans="0000";
void Main(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[1]='1';
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				ans[2]='1';
				if(abs(s1[2]-s2[2])==1) ans[3]='1';
			}
		}
	}
	cout<<ans;
}}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	FZT::Main();
	return 0;
}
