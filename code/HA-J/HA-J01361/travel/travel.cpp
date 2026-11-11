#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0; 
    }
    if(b[0]==d[0]&&b[1]==d[1]){
    	cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'||b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'){
		cout<<1;
		
		if(b[2]+1==d[2]||d[2]+1==b[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0<<0;
	}
	
	return 0;
}