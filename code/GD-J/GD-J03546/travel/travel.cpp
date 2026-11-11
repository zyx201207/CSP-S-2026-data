
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	if(a == b){
		cout<<"1";
		int m,n;
		m = (int)(x[0] - '0') + (int)(x[1] - '0');
		n = (int)(y[0] - '0') + (int)(y[1] - '0');
		if(m == n){
			cout<<"1";
			if((x[2] - 'C' <= 0 && y[2] - 'C' <= 0) || (x[2] - 'C' > 0 && y[2] - 'C' > 0)){
				cout<<"1";
				if(abs((int)(x[2] - y[2])) == 1) cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
} 
