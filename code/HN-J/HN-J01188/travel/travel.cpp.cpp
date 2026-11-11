#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int i=0;
	while(i<=1){
		if(c1[i]!=c2[i]){
			cout<<"0000";
			return 0;
		}
		i++;
	}
	i=0;
	while(i<=1){
		if(s1[i]!=s2[i]){
			cout<<"1000";
			return 0;
		}
		i++;
	}
	if(abs(s1[2]-s2[2])>=1 and max(s1[2],s2[2])=='D'){
		cout<<"1100";
		return 0;
	}
	if(abs(s1[2]-s2[2])>=3 and max(s1[2],s2[2])=='F'){
		cout<<"1100";
		return 0;
	}
	if(max(s1[2],s2[2])<'D')
		if(abs(s1[2]-s2[2])!=1){
			cout<<"1110";
			return 0;
		}
	cout<<"1111";
	return 0;
}
