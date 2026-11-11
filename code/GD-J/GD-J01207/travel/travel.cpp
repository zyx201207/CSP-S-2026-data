#include<iostream>
#include<cstdio>
using namespace std;
string ra,rb,xa,xb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ra>>rb>>xa>>xb;
	if(ra!=xa) cout<<"0000";
	else{
		if(rb[0]!=xb[0]||rb[1]!=xb[1]) cout<<"1000";
		else{
			int r=rb[2],x=xb[2];
			int ma=max(r,x),mi=min(r,x);
			if(ma>='D'&&mi<='C') cout<<"1100";
			else{
				if(ma-mi==1||(ma=='F'&&mi=='D')) cout<<"1111";
				else cout<<"1110";
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
