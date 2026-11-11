#include<bits/stdc++.h>
using namespace std;
string cyi,cer,syi,ser;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cyi>>syi>>cer>>ser;
	if(cyi==cer){
		cout<<1;
		if(syi[0,1]==ser[0,1]){
			cout<<1;
			if(syi[2]<='C'){;
				if(ser[2]<='C'){
					cout<<1;
					if(syi[-2]=='B'||ser[2]=='B')cout<<1;
					else cout<<0;
				}else cout<<0<<0;
			}else{
				if(ser[2]<='C'){
					cout<<0<<0;
				}else cout<<1<<1;
			}
		}else cout<<0<<0<<0;
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
