#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;
string c1,c2,z1,z2,pai1,pai2;
char lie1,lie2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>z1>>z2;
	if(c1!=z1){
		cout<<"0000";
		exit(0);
	}
	pai1=c2[0];
	pai1+=c2[1];
	pai2=z2[0];
	pai2+=z2[1];
	if(pai1!=pai2){
		cout<<"1000";
		exit(0);
	}
	lie1=c2[2];
	lie2=z2[2];
	if(lie1<'D'&&lie2<'D'){
		if(abs(lie1-lie2)>1){
			cout<<"1110";
			exit(0);
		}else{
			cout<<"1111";
			exit(0);
		}
	}else if(lie1>'D'&&lie2>'D'){
		if(abs(lie1-lie2)>1){
			cout<<"1110";
			exit(0);
		}else{
			cout<<"1111";
			exit(0);
		}
	}else{
		cout<<"1100";
		exit(0);
	}
	return 0;
}
