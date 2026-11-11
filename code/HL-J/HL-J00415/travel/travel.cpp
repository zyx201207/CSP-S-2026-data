#include <bits/stdc++.h>
using namespace std;
int tong[7];
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string s1,s2,c1,c2;
	cin>>s1>>s2>>c1>>c2;
	if(s1!=c1){
		cout<<"0000";
		return 0;
	}
	string p1=s2.substr(0,2);
	string p2=c2.substr(0,2);
	if(p1!=p2){
		cout<<"1000";
		return 0;
	}
	char a=s2[2],b=c2[2];
	tong[a-'A'+1]=1;tong[b-'A'+1]=1;
	int cnt=0;
	for(int i=1;i<=3;i++){
		if(tong[i]==1) cnt++;
	}
	if(cnt==1){
		cout<<"1100";
		return 0;
	}else if(cnt==2){
		if((a=='A' && b=='C') || (b='A' && a=='C')){
			cout<<"1110";
			return 0;
		}else{
			cout<<"1111";
			return 0;
		}
	}else{
		cout<<"1111";
		return 0;
	}
	return 0;
}
