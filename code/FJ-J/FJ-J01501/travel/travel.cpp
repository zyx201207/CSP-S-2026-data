#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int rx, mx;
string rb, mb;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	cin>>rx>>rb>>mx>>mb;
	if(rx!=mx) printf("0000");
	else{
		int r=0, m=0;
		for(int i=0; i<2; i++) r=r*10+(rb[i]-'0');
		for(int i=0; i<2; i++) m=m*10+(mb[i]-'0');
		if(r!=m) printf("1000");
		else{
			if((rb[2]<='C'&&mb[2]>='D')||(rb[2]>='D'&&rb[2]<='C')) printf("1100");
			else{
				if(abs(rb[2]-mb[2])!=1) printf("1110");
				else printf("1111");
			}
		}
	}
	return 0;
}
