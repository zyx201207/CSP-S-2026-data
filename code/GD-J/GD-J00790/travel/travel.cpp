#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=1e5+5;
int ans[4],c[10];
int func(string s){
	int t=0;
	for(int i=0;i<s.size();i++)
		t=t*10+s[i]-'0';
	return t;
} 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2; 
	c[3]=c[5]=1;
	if(c1==c2){
		ans[0]=1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			ans[1]=1;
			if(c[s1[2]-'A']==c[s2[2]-'A']){
				ans[2]=1;
				if(abs(s1[2]-s2[2])==1)
					ans[3]=1;
			} 
		}
		if(abs(func(s1.substr(0,2))-func(s2.substr(0,2)))==1&&s1[2]==s2[2]){
			ans[3]=1;
		}
	}
	for(int i=0;i<4;i++)
		cout<<ans[i]; 
	return 0;
}
