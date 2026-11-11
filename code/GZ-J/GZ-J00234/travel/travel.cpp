//李昊燃 华东师范附属贵阳学校 GZ-J 00234
#include<bits/stdc++.h>
using namespace std;
long long cnt1,cnt2;
string a,b,r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>r>>b>>x;
	for(int i=0;i<=1;i++){
		cnt1+=a[i]-'0';
		cnt2+=b[i]-'0';
	}
	if(cnt1==cnt2) cout<<1;
	else {
		cout<<"0000"; 
		return 0;
	}
	cnt1=0;cnt2=0;
	for(int i=0;i<=1;i++){
		cnt1+=r[i]-'0';
		cnt2+=x[i]-'0';
	}
	if(cnt1==cnt2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	cnt1=r[2]-'A';cnt2=x[2]-'A';
	if((cnt1<=2&&cnt2<=2)||(cnt1>2&&cnt2>2)) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(cnt1-cnt2==1||cnt1-cnt2==-1) cout<<1;
	else cout<<0;
	return 0;
}

