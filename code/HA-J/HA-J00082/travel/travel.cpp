#include<bits/stdc++.h>
using namespace std;
string c1,c2, s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1<s2){
			cout<<111;
		}else{
			cout<<000;
		}
	}else{
		cout<<0000;
	}
	return 0;
}
