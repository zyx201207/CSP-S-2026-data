#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char e,f;
	cin>>a>>c>>e>>b>>d>>f;
	if(a==b){
		cout<<"1";
		if(c==d){
			cout<<"1";
			if(e=='A' || e=='B' || e=='C'){
				if(f=='A' || f=='B' || f=='C')
				{
					cout<<"1";
					int x1,x2;
					x1=e;
					x2=f;
			    	if(x1==x2-1 || x2==x1-1) cout<<"1";
					else cout<<"0";
				}
				else cout<<"00";
			}
			else{
				if(f=='D' || f=='F'){
					cout<<"1";
					int x1,x2;
					x1=e;
					x2=f;
					if(x1==x2-1 || x2==x1-1) cout<<"1";
					else cout<<"0";
				}
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";

	return 0;
}
