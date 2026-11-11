#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,s1,c2,s2;
ll f=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
		f=0;
	}
	if(f){
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				f=0;
			}
		}
		cout<<f;
	}
	else{
		cout<<0;
		f=0;
	}
	if(f){
		if((s1[2]<='C' && s2[2]>='A' && s1[2]>='A' && s2[2]<='C') || (s1[2]<='F' && s2[2]>='D' && s1[2]>='D' && s2[2]<='F')) cout<<1;
		else{
			cout<<0;
			f=0;
		}
	}
	else cout<<0;
	if(f){
		if((s1[2]=='D' && s2[2]=='F') || (s2[2]=='D' && s1[2]=='F')) cout<<1;
		else if(abs(s1[2]-s2[2])==1) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
