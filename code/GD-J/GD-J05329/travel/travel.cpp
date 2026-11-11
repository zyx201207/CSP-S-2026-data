#include <bits/stdc++.h>
using namespace std;
string rc,xc,rs,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>rc>>rs>>xc>>xs;
	if(rc[0]==xc[0]&&rc[1]==xc[1]){
		if(rs[0]==xs[0]&&rs[1]==xs[1]){
			if(((rs[2]>='A'&&rs[2]<='C')&&(xs[2]>='A'&&xs[2]<='C'))||((rs[2]>='D'&&rs[2]<='F')&&(xs[2]>='D'&&xs[2]<='F'))){
				if(abs(int(rs[2])-int(xs[2]))==1){
					cout<<"1111";
				}
				else{
					cout<<"1110";
					return 0;
				}
			}
			else{
				cout<<"1100";
				return 0;
			}
		}
		else{
			cout<<"1000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
