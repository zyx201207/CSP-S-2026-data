#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sa,sb;
	int a,b;
	cin>>a>>sa>>b>>sb;
	if(a==b){
		cout<<1;
		if(sa[0]==sb[0]&&sa[1]==sb[1]){
			cout<<1;
			if(sa[2]<='C'&&sb[2]<='C'){
				cout<<1;
				if(sa[2]+1==sb[2]||sa[2]-1==sb[2]){
					cout<<1;
				}else cout<<0;
			}else if(sa[2]>='D'&&sb[2]>='D'){
				cout<<1;
				if(sa[2]+1==sb[2]||sa[2]-1==sb[2]){
					cout<<1;
				}else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
