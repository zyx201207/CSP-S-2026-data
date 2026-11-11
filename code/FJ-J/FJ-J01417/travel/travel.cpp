#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool ans[5]={false,false,false,false,false};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if((c1[0]==c2[0])&&(c1[1]==c2[1])) ans[1]=true;
	if((s1[0]==s2[0])&&(s1[1]==s2[1])){
		ans[2]=true;
		if((s1[2]-'A'<=2 &&s2[2]-'A'<=0)||(s1[2]-'A'>=3 &&s2[2]-'A'>=3)){
			ans[3]=true;
			if(abs((s1[2]-'A')-(s2[2]-'A'))<=1){
				ans[4]=true;
			}
		}
	}
	int t=1;
	while(t<=4){
		if(ans[t]) cout<<"1";
		else cout<<"0";
		t++;
	}
	return 0;
}
