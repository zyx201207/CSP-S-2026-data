#include<bits/stdc++.h>
using namespace std;
int a,l=12;
string k;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	while(l!=0){
		k=char(l%2+'0')+k;
		l/=2;
	}
	cout<<k;
	return 0;
}
