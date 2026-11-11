#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	string ca,sa,cb,sb;
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb)cout<<1;
	else{
		cout<<"0000\n";
		return 0;
	}if(sa[0]==sb[0]&&sa[1]==sb[1])cout<<1;
	else{
		cout<<"000\n";
		return 0; 
	}if((sa[2]<'D'&&sb[2]<'D')||(sa[2]>'C'&&sb[2]>'C'))cout<<1;
	else{
		cout<<"00\n";
		return 0;
	}cout<<(abs(sa[2]-sb[2])==1)<<'\n';
	return 0;
}
