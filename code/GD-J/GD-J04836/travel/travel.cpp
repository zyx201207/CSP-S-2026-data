#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0); 
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int w1=s1[2]-'A'+1,w2=s2[2]-'A'+1;
	if(w1==6)w1--;
	if(w2==6)w2--;
	//cout<<w1<<w2;
	//return 0;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	else if(((w1==1||w1==2||w1==3)&&(w2==4||w2==6))||((w2==1||w2==2||w2==3)&&(w1==4||w1==6))){
		cout<<"1100";
		return 0;
	}
	else if((w1+1)!=w2&&(w1-1)!=w2){
		cout<<"1110";
		return 0;
	}
	else{
		cout<<"1111";
		return 0;
	}
}
