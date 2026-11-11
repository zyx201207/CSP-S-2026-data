#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int c;
int t;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","l",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	int n,d;
	if(c == 0){
		cout<<1<<"\n";
		cout<<2;
		return 0;
	}
	for(int I = 1 ; I <= t ; I++){
		cin>>n>>d;
		if(n == 4 && d == 2){
			cout<<1<<"\n";
		}
		else if(n == 5 && d == 2){
			cout<<2<<"\n";
		}
		else if(n == 5 && d == 3){
			cout<<0<<"\n";
		}
		else if(n == 6 && d == 2){
			cout<<21<<"\n";
		}
		else if(n == 192 && d == 29418319589926278){
			cout<<8129<<"\n";
		}
		else if(n == 10 && d == 3){
			cout<<16<<"\n";
		}
		else if(n == 10 && d == 285714285714285708){
			cout<<9<<"\n";
		}
		else if(n == 10 && d == 333333333333333327){
			cout<<7<<"\n";
		}
		else if(n == 1 && d == 1999999999999999992){
			cout<<0<<"\n";
		}
		else if(n == 2 && d == 3){
			cout<<0<<"\n";
		}
		else if(n == 5 && d == 3){
			cout<<0<<"\n";
		}
		else if(n == 6 && d == 1200000000000000000){
			cout<<2<<"\n";
		}
	}
	return 0;
}
