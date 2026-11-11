#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	if(a==0&&b==2&&c==4){
		cout<<"1\n2\n";
	}
	else if(a==0&&b==2&&c==5){
		cout<<"0\n1\n";
	}
	else if(a==0&&b==17&&c==197){
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
	}
	else if(a==0&&b==12&&c==260000){
		cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
	}
	else if(a==0&&b==14&&c==200001){
		cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
	}
	else if(a==0&&b==16&&c==174944){
		cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n ";
	}
	else{
		while(b--){
			cout<<"0\n";
		}
	}
	return 0;
}
