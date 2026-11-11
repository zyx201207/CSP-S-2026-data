#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
typedef long long ll;
int cx1,cx2;
string zw1,zw2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cx1>>zw1>>cx2>>zw2;
	if(cx1==cx2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(zw1[1]==zw2[1]&&zw1[0]==zw2[0]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(((zw1[2]>='A'&&zw1[2]<='C'&&zw2[2]>='A'&&zw2[2]<='C')||((zw1[2]=='D'&&zw2[2]=='F')||(zw1[2]=='F'&&zw2[2]=='D')))){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(((zw1[2]-1==zw2[2]||zw1[2]+1==zw2[2])&&((zw1[2]!='C'&&zw2[2]!='D')||(zw1[2]!='D'&&zw2[2]!='C'))))cout<<1;
	else{
		cout<<0;
		return 0;
	}
    return 0;
}
