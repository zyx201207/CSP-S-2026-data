#include<bits/stdc++.h>
const int N=1e5+5;
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char zwr,zwx;
	cin>>a>>c>>zwr>>b>>d>>zwx;
	if(a==b){
		cout<<1;
		if(c==d){
			cout<<1;
			if(('A'<=zwr&&zwr<='C'&&'A'<=zwx&&zwx<='C')||('D'<=zwr&&zwr<='F'&&'D'<=zwx&&zwx<='F')){
				cout<<1;
				if(abs(zwr-zwx)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
