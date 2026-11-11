#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;int ans=0;cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+=1000;
		if(s1[1]==s2[1] and s1[2]==s2[2])
			ans+=100;
		if(s1[3]-s2[3]<=2){
			ans+=10;
			if(s1[3]-s2[3]<=1)
				ans+=1;
		}}
	if(ans==0){
		cout<<'0000';}	
	else cout<< ans;
	
	
}
