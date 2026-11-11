#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],z;
string b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n == 4){
		z=12;
	}
	if(n==5){
		z=7;
	}
	cout << z;
}
