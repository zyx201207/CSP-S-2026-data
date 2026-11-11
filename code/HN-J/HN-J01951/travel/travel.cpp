#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	string n,m,x,y;
	cin>>n>>m>>x>>y;
	if(n==x){
		int i=0;
		if(m[i]==y[i]&&m[i+1]==y[i+1]){
			if((m[i+2]=='C'&&y[i+2]=='D')||(m[i+2]=='D'&&y[i+2]=='C')){
				cout<<"1100";
			}else{
				if((m[i+2]=='C'&&y[i+2]=='A')||(m[i+2]=='A'&&y[i+2]=='C')){
					cout<<"1110";
				}else{
					cout<<"1111";
				}
			}
		}else{
			cout<<"1000";
		}
	}else cout<<"0000";
}
