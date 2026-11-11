#include<bits/stdc++.h>
#define ll long long
using namespace std;
int nx,ny,nz,mx,my,mz;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>nx>>s;ny=(s[0]-'0')*10+(s[1]-'0');nz=(s[2]-'A');
	cin>>mx>>s;my=(s[0]-'0')*10+(s[1]-'0');mz=(s[2]-'A');
	if(nx==mx){
		if(ny==my){
			if((nz<3&&mz<3)||(nz>2&&mz>2)){
				if(abs(nz-mz)==1) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
