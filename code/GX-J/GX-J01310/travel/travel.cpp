#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a==b){
		if(x[0]+x[1]==y[0]+y[1]){
			if((x[2]<='C'&&y[2]<='C')||(x[2]>='D'&&y[2]>='D')){
				if(x[2]==y[2]+1||x[2]+1==y[2]) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
