#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;	
	}
	long long a=(s1[0]-'0')*10+(s1[1]-'0');
	long long b=(s2[0]-'0')*10+(s2[1]-'0');
	if(a==b){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	long long a1=s1[2]-'A'+1;
	long long b1=s2[2]-'A'+1;
	if((a1<=3 && b1<=3) || (a1>=4 && b1>=4)){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(a1-b1)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
