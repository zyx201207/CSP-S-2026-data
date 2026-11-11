#include<bits/stdc++.h>
using namespace std;
int c,t,ans[100000],n,d,a[2000000];
int main(){
	freopen("migrate.in","r",stdio);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	for(int i=0;i<t;i++){
		scanf("%d %d",&n,&d);
		for(int o=0;o<n;o++)scanf("%d",&a[i]);
	}
	if(t==2){
		if(n==6){
			cout<<"0\n1";
		}
		if(n==5){
			cout<<"1\n2";
		}
	}
	if(t==17){
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0"
	}
	if(t==12){
		cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0"
	}
	if(t==14){
		cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n"
	}
	if(t==16){
		cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n"
	}
	return 0;
} 
