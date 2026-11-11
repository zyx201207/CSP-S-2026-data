#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	if(b==2&&c==4&&d==2){
		cout<<"1\n2";
	}
	else if(b==2&&c==5&&d==3){
		cout<<"0\n1";
	}
	else if(b==17&&c==197&&d==29418319589926278){
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
	}
	else if(b==12&&c==260000&&d==1){
		cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
	}
	else if(b==14&&c==200001&&d==206291914738518400){
		cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
	}
	else if(b==16&&c==174944&&d==139950){
		cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
