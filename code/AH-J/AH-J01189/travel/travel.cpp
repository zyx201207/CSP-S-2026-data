#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string ax,bx;
	string ah,bh;
	cin>>ax>>ah>>bx>>bh;
	bool tcx=false,tp=false,tc=false,xl=false;
	if(ax==bx){
        tcx=true;
        if(ah[0]==bh[0]&&ah[1]==bh[1]){
            tp=true;
            if((ah[2]>='A'&&ah[2]<='C'&&bh[2]>='A'&&bh[2]<='C')||(ah[2]>='D'&&ah[2]<='F'&&bh[2]>='D'&&bh[2]<='F')){
                tc=true;
                if((ah[2]==(bh[2]+1))||(ah[2]==(bh[2]-1))){
                    xl=true;
                }
            }
        }
	}
	cout<<tcx<<tp<<tc<<xl<<endl;
	return 0;
}
