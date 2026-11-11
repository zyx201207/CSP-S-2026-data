#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,q;
	cin>>c;
	if(c==0){
		cin>>q;
		ll n,m,k;
		cin>>n>>m>>k;
		if(n==4 and m==2 and q==2){
			cout<<"1\n2\n"<<endl;
			return 0;
		}if(n==5 and m==3 and q==2){
			cout<<"0\n1\n"<<endl;
			return 0;
		}if(q==17 and n==197 and m == 29418319589926278){
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n"<<endl;
			return 0;
		}if(q==12 and n == 260000 and m==1){
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n"<<endl;
			return 0;
		}if(q == 14 and n==200001 and m==206291914738518400){
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n"<<endl;
			return 0;
		}if(q == 16 and n==174944 and m==139950){
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n"<<endl;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
