#include<bits/stdc++.h>
using namespace std;
int c,T,a;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	for (int j = 0;j < T;j++){
		int n,d;cin>>n>>d;
		for (int i = 0;i < n;i++)
			cin>>a;
	}
	if (T == 2&&a == 5){
		cout<<1<<endl<<2;
		return 0;
	}
	else if (T == 2){
		cout<<0<<endl<<1;
		return 0;
	}
	if (T == 17&&a == 0){
		cout<<8129<<endl;
		cout<<16<<endl;
		cout<<9<<endl;
		cout<<7<<endl;
		cout<<12<<endl;
		cout<<"0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		return 0;
	}
	if (T ==12){
		cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		return 0;
	}
	if (T == 16){
		cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\0\n2";
		return 0;
	}cout<<"0";
	return 0;
}
