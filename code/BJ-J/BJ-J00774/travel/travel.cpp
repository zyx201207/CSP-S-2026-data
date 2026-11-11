#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans,ans1;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c) {
		cout<<1;
		ans=b[0];
		ans+=b[1];
		ans1=d[0];
		ans1+=d[1];
		if(ans==ans1) {
			cout<<1;
			if(d[2]>='A'&&b[2]>='A'&&b[2]<='C'&&d[2]<='C'){
				cout<<1;
				if((b[2]==d[2]+1)||(d[2]==b[2]+1)){
				    cout<<1;
				}
				else{
					cout<<0;
				}
				return 0;
			}
			else if(b[2]>='D'&&d[2]>='D'&&b[2]<='F'&&d[2]<='F'){
				cout<<1;
				if((b[2]==d[2]+1)||(d[2]==b[2]+1)){
				    cout<<1;
				}
				else cout<<0;
				return 0;
			}
			else {
				cout<<"00";
				return 0;
			}
		}
		else {
			cout<<"000";
			return 0;
		}
	}
	else {
		cout<<"0000";
	}
    return 0;
}