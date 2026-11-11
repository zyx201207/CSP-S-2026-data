#include<bits/stdc++.h>
using namespace std;
int a,b,d,e;
char c,f;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d>>e>>f;
	if(a==d){
		cout<<1;
		if(b==e){
			cout<<1;
			int x=c-'A',y=f-'A';
			if((x<=2&&y<=2)||(x>2&&y>2)){
				cout<<1;
				if(abs(x-y)==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
