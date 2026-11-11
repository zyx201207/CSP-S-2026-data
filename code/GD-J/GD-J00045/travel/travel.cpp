#include<bits/stdc++.h>
using namespace std;
long long a,b,d,e;
char c,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d>>e>>f;
	if(a!=d){
		cout<<"0000";
		return 0;
	}
	if(b!=e){
		cout<<"1000";
		return 0;
	}
	if((c<='C'&&f>='D')||(f<='C'&&c>='D')){
		cout<<"1100";
		return 0;
	}
	if(abs(f-c)!=1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
