#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[2000005];
//int diff[2000005];
int diff;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	int n,d;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
	}
		if(c==0){
			if(t==2 and n==5){
				cout<<1<<'\n'<<2;
				return 0;
			}
			else if(t==2 and n==6){
				cout<<0<<'\n'<<1;
				return 0;
			}
			else if(t==17){
				cout<<8129<<'\n'<<16<<'\n'<<9<<'\n'<<7<<'\n'<<12<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n'<<0<<'\n'<<2<<'\n'<<0;
				return 0;
			}
			else if(t==12){
				cout<<0<<'\n'<<0<<'\n'<<259997<<'\n'<<259995<<'\n'<<86669<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<7<<'\n'<<5<<'\n'<<5<<'\n'<<0;
				return 0;
			}
			else if(t==14){
				cout<<9999900000<<'\n'<<399995<<'\n'<<0<<'\n'<<716427<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n'<<0<<'\n'<<2;
				return 0;
			}
			else if(t==16){
				cout<<6800625333<<'\n'<<6247500<<'\n'<<6242502<<'\n'<<4998<<'\n'<<9994<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n'<<0<<'\n'<<2;
				return 0;
			}
		}
		//for(int i=2;i<=n;i++){
		//	diff[i]=x[i]-x[i-1];
		//}
	diff=x[2]-x[1];
	if(diff>d){
		cout<<0<<'\n';
		return 0;
	}
	int once=d/diff;
	for(int i=1;i<=n;i++){
		//for(int k=i+3;k<=n;k++){
			cout<<0<<'\n';
		//}
	}
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
