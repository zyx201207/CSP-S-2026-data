#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	if(a!=b){
		cout<<"0000"<<'\n';
		return 0;
	}
	bool f=0;
	for(int i=0; i<2; i++) {
		if(a1[i]!=b1[i])f=1;
	}
	if(f==1) {
		cout<<1000<<'\n';
		return 0;
	}
	if('A'<=a1[2]&&a1[2]<='C') {
		if('A'<=b1[2]&&b1[2]<='C') {
			if(a1[2]+1==b1[2]) {
				cout<<1111;
				return 0;
			} else if(b1[2]+1==a1[2]) {
				cout<<1111;
				return 0;
			} else {
				cout<<1110;
				return 0;
			}
		} else {
			cout<<1100<<'\n';
			return 0;
		}
	}
	if(a1[2]=='D'||a1[2]=='F') {
		if(b1[2]=='D'||b1[2]=='F') {
			cout<<1111<<'\n';
			return 0;
		} else {
			cout<<1100<<'\n';
			return 0;
		}
	}

	return 0;
}
