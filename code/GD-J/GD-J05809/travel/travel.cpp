#include<bits/stdc++.h>
using namespace std;


string c1,c2,s1,s2;
string b1,b2;
bool ans[4];
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
//ios::sync_with_stdio(false);
//cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	b1 = s1[2];
	b2 = s2[2];
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		ans[0]=true;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[1]=true;
			if((b1=="A"&&(b2=="B"||b2=="C")) ||(b1=="B"&&(b2=="A"||b2=="C")) ||(b1=="C"&&(b2=="A"||b2=="B"))){
				ans[2] = true;
				if((b1=="B"||b2=="B")&&(b1=="A"||b2=="A"||b1=="C"||b2=="C")){
					ans[3] = true;
				}
			}
			else if((b1=="D"&&b2=="F") ||(b2=="D"&&b1=="F")){
				ans[2] = true;
				ans[3] = true;
			}
			
			}
}
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
return 0;
}

