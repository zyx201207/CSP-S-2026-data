#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=0;i<2;i++){
		if(a[i]!=c[i]){
			cout<<0<<0<<0<<0;
			return 0;
		}
	}
	cout<<1;
	for(int i=0;i<2;i++){
		if(b[i]!=d[i]){
			cout<<0<<0<<0; 
			return 0;
		}
	}
	cout<<1;
	int b1=b[2]-'A';
	int d1=d[2]-'A'; 
	if(b1<=2&&d1<=2){
		cout<<1;
	}else if(b1>=3&&d1>=3){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(abs(b1-d1)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
