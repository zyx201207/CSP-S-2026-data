#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string b,d;
	int a,c;
	cin>>a>>b>>c>>d;
	string s,s1;
	s+=b[0]+b[1];
	s1+=d[0]+d[1];
	if(a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s!=s1){
		cout<<0;
	}else{
		cout<<1;
		if(b[2]>='D'&&d[2]>='D'){
			cout<<11;
		}else if(b[2]<='C'&&d[2]<='C'){
			cout<<1;
			if(b[2]+1==d[2]||d[2]+1==b[2]||b[2]-1==d[2]||d[2]-1==b[2]){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0<<0;
		}
	}
	return 0;
}
