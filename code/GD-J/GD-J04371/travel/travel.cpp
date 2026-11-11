#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int s[10],cnt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++){
		if(c1[i]!=c2[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<1;
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	s[s1[2]-'A']++;
	s[s2[2]-'A']++;
	for(int i=0;i<=2;i++)cnt+=s[i];
	if(cnt==1){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(cnt==0){
		cout<<1;
	}else{
		if(s[0]==1&&s[2]==1)cout<<0;
		else cout<<1;
	}
	return 0;
} 
