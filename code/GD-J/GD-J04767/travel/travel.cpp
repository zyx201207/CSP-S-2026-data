#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string R="";
	string X="";
	string r="";
	string x="";
	cin>>R>>r>>X>>x;
	if(R==X){
		cout<<1;
		if(r[0]==x[0]&&r[1]==x[1]){
			cout<<1;
			if((r[2]<=67&&x[2]<=67)||(r[2]>67&&x[2]>67)){
				cout<<1;
				if(r[2]<=67){
					if(r[2]-x[2]==1||x[2]-r[2]==1){
						cout<<1;
					}
					else cout<<0;
				}
				else cout<<1;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
