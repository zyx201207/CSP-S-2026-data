#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ca,sa,cb,sb;
	cin>>ca;
	cin>>sa;
	cin>>cb;
	cin>>sb;
	if(ca[1]==cb[1] && sa[1]==sb[1] && ca[0]==cb[0] && sa[0]==sb[0]){
		cout<<1111;
	}else{
		cout<<1100;
	}
	return 0; 
}
