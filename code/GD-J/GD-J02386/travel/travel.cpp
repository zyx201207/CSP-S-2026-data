#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	bool ans1=(c1==c2),ans2=ans1&&(s1.substr(0,2)==s2.substr(0,2)),ans3=ans2&&((s1[2]<='C')==(s2[2]<='C')),ans4=ans3&&(abs(s2[2]-s1[2])==1);
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
