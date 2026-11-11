#include<bits/stdc++.h>
using namespace std;
#define int long long
int a1,a2,b1,b2;
char c1,c2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a1>>a2>>c1>>b1>>b2>>c2;
	if(a1==b1){
		cout<<1;
		if(a2==b2){
			cout<<1;
			if((c1<='C'&&c2<='C')||(c1>='D'&&c2>='D')){
				cout<<1;
				if(abs(c1-c2)==1)cout<<1;
				else cout<<0;	
			}else cout<<"00";	
		}else cout<<"000";
	}else{
		cout<<"0000";
	}
	return 0;
}
