#include<bits/stdc++.h>
using namespace std;

int S1,C1,S2,C2;
char K1,K2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C1>>S1>>K1>>C2>>S2>>K2;
	if(C1!=C2) cout<<"0000";
	else{
		if(S1!=S2) cout<<"1000";
		else{
			if(K1>='A'&&K1<='C'&&K2>='D'&&K2<='F') cout<<"1100";
			else if(K1>='D'&&K1<='F'&&K2>='A'&&K2<='C') cout<<"1100";
			else{
				if(K1=='A'&&K2=='C') cout<<"1110";
				else if(K2=='A'&&K1=='C') cout<<"1110";
				else cout<<"1111"; 
			}
		} 
	}
	return 0;
}
