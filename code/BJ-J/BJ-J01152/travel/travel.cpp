#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
ll to_int(string s){
	ll ans;
	for(int i=0;i<2;i++){
		ans*=10;
		ans+=s[i]-'0';
	}
	return ans;
}
ll check(char c1,char c2){
	if(c1>c2)swap(c1,c2);
	if((c1<='C')&&(c2>='D')){
	//	cout<<c1<<' '<<c2<<'\n';
		return 0;
	}else if(c2-1==c1){
		return 2;
	}else{
		return 1;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	ll tmp1=to_int(s1);
	ll tmp2=to_int(s2);
	ll tmp3=to_int(s3);
	ll tmp4=to_int(s4);
	ll x=check(s2[2],s4[2]);
//	cout<<check('A','C')<<'\n';
	if(tmp1!=tmp3){
		cout<<"0000";
	}else if(tmp2!=tmp4){
		cout<<"1000";
	}else if(x==0){
		cout<<"1100";
	}else if(x==1){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	return 0;
}
