#include<bits/stdc++.h>
#define int long long
using namespace std;
int a1,a2,b1,b2;
char a,b;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>a>>b1>>b2>>b;
	if(a1==b1){
		cout<<1;
		if(a2==b2){
			cout<<1;
			if(a<='C'&&b<='C'){
				cout<<1;
				int aa=a-'A',bb=b-'A';
				if(a+1==b||b+1==a){
					cout<<1;
				}
				else{
					cout<<0;
				}
			} 
			else if(a>='D'&&b>='D'){
				cout<<11; 
			} 
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
