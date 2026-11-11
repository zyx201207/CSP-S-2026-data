#include<bits/stdc++.h>
using namespace std;
long long n,k,o;
string a,b,c,d,ans_b,ans_d;
char stg_b,stg_d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(b==d){
		cout<<"0000";
		return 0;
	}
	if(a==c)
		cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<3;i++){
		if(b[i]>='0'&&b[i]<='9')
			ans_b+=b[i];
		if(b[i]>='A'&&b[i]<='F')
			stg_b=b[i];
		if(d[i]>='0'&&d[i]<='9')
			ans_d+=d[i];
		if(d[i]>='A'&&d[i]<='F')
			stg_d=d[i];
	}
	if(ans_b==ans_d) 
		cout<<1;
	else{
		cout<<"000";return 0;
	}
	if(stg_b<='C'&&stg_d<='C')
		cout<<1;
	else if(stg_b>='D'&&stg_d>='D'){
		cout<<"11";return 0;
	}
	else{
		cout<<"00";return 0;
	}
	if(abs(stg_b-stg_d)==1)
		cout<<1;
	else
		cout<<0;
	return 0;
}
