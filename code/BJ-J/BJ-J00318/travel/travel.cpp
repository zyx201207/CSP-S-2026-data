#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string a,aa,b,bb;
	cin>>a>>aa>>b>>bb;
	bool f=0;
	for(int i=0;i<2;i++){
		if(a[i]!=b[i]) f=1;
	}
	if(f) cout<<"0000";
	else{
		for(int i=0;i<2;i++){
			if(aa[i]!=bb[i]) f=1;
		}
		if(f) cout<<"1000";
		else{
			if(aa[2]<='C'&&bb[2]<='C'){
				if(aa[2]=='B' || bb[2]=='B'){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else if(aa[2]>'C'&&bb[2]>'C'){
				if(aa[2]=='D' || bb[2]=='D'){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else{
				cout<<"1100";
			}
		}
	}
	return 0;
}
