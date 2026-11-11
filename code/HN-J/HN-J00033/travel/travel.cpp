#include<bits/stdc++.h>
using namespace std;
int r1,r2,x1,x2;
char r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>r1>>r2>>r>>x1>>x2>>x;
	if(r1==x1){
		cout<<1;
			if(r2==x2){
				cout<<1;
				if((r+x<=133)||(r+x=='D'+'F')){
					cout<<1;
					if(r-x==1||x-r==1||r+x==138)cout<<1;
					else cout<<0;
				}else cout<<"00";
			}
			else cout<<"000";
	}else cout<<"0000";
	return 0;
}
