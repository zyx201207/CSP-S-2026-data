#include<bits/stdc++.h>
using namespace std;
int a,b;
string aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>a>>aa>>b>>bb;
	if(a==b){
		cout<<1;
		if(aa[0]==bb[0]&&aa[1]==bb[1]){
			cout<<1;
			if(!(aa[2]>'C'^bb[2]>'C')){
				cout<<1;
				if(abs(aa[2]-bb[2])==1)cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
}

