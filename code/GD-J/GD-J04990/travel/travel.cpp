#include <bits/stdc++.h>
using namespace std;
string a,b,n,m;
int f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>n>>b>>m;
	if(a==b){
		f=1;
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(f){
		f=0;
		if(n[0]==m[0] && n[1]==m[1]){
			f=1;
			cout<<1;
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"000";
		return 0;
	}
	if(f){
		f=0;
		if((n[2]<='C' && m[2]<='C') || ((n[2]>='D' && m[2]>='D'))){
			cout<<1;
			f=1;
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		cout<<"00";
		return 0;
	}
	if(f){
		if((n[2]+1)==m[2] || (n[2]-1)==m[2]){
			cout<<1;
		}else if((n[2]=='F' && m[2]=='D') || (n[2]=='D' && m[2]=='F')){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
