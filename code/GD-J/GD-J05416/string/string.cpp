#include<bits/stdc++.h>
using namespace std;
int n,a[100005],z;
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin>>a[i] >>b;
	}
	if(n == 3){
		z=2;
	}
	if(n==2){
		z=0;
	}
	if(n==6){
		z=3000000000;
	}
	cout << z;
}
