#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r1=0,x1=0;
	string r2,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(r2[0]==x2[0] and r2[1]==x2[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
//	cout<<r2[2]<<" "<<x2[2]<<" "<<7;
	if(r2[2]=='A' or r2[2]=='B' or r2[2]=='C'){
		if(x2[2]=='A' or x2[2]=='B' or x2[2]=='C'){
			cout<<1;
			if(r2[2]+1==x2[2] or r2[2]-1==x2[2]){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0<<0;
		}
	}else{
		cout<<1<<1;
	}
	return 0;
}

