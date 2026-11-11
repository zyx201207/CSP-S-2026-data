#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	ll key=1;
	for(int i=0;i<2;i++){
		if(c2[i]!=s2[i]){
			key=0;
		}
	}
	if(key==1){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	//cout<<c2[2]<<" "<<s2[2];
	if(c2[2]<='C'&&s2[2]<='C'){
		cout<<1;
		if(abs(c2[2]-s2[2])==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(c2[2]>='D'&&s2[2]>='D'){
		cout<<1;
		if(abs(c2[2]-s2[2])==2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<"00";
	}
	return 0;
}
