#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b,x,y;
	cin>>a>>x>>b>>y;
	int r=x[2]-'A'+1,s=y[2]-'A'+1;
	if(a==b){
		cout<<1;
		if(x[0]==y[0]&&x[1]==y[1]){
			cout<<1;
			if((x[2]<='C'&&y[2]<='C')||(x[2]>='D'&&y[2]>='D')){
				cout<<1;
				if(abs(r-s)==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
