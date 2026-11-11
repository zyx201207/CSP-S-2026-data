#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<2;i++){
		if(a[i]!=c[i]){
			cout<<"0000";
			return 0;
		}
	}
	for(int i=0;i<=1;i++){
		if(b[i]!=d[i]){
			cout<<"1000";
			return 0;
		}
	}
	if(b[2]>='D' && d[2]<='C'){
		cout<<"1100";
		return 0;
	}
	if(b[2]<='C' && d[2]>='D'){
		cout<<"1100";
		return 0;
	}
	if(abs(int(b[2]-d[2]))!=1){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	return 0;
} 
