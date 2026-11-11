#include<bits/stdc++.h>
using namespace std;
long long a,b;
char a1[100000],a2[100000];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>a2;
	if(a==b){
		cout<<1;
	}else{
		cout<<0000;
		return 0;
	}
	if(a1[0]==a2[0]&&a1[1]==a2[1]){
		cout<<1;
	}else{
		cout<<000;
		return 0;
	}
	if(a1[0]==a2[0]&&a1[1]==a2[1]&&((a1[2]>'c'&&a2[2]>'c')||(a1[2]<='c'&&a2[2]<='c'))){
		cout<<1;
	}else{
		cout<<00;
		return 0;
	}
	if(a1[0]==a2[0]&&a1[1]==a2[1]&&((a1[2]>'c'&&a2[2]>'c')||(a1[2]<='c'&&a2[2]<='c'))&&((a1[2]-1)/1.0==a2[2]/1.0||(a1[2]+1)/1.0==a2[2]/1.0)){
		cout<<1;
	}else{
		cout<<0;
		return 0;
	}
	return 0;
}
