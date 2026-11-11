#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			int l1=(b[2]=='D'||b[2]=='E'),l2=(d[2]=='D'||d[2]=='E');
			if(l1==l2){
				cout<<1;
				if(abs(b[2]-d[2])==1) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;
    return 0;
}
