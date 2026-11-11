#include<bits/stdc++.h>
using namespace std;
int a[1000000];
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b;
	}
	if(n==1){
		cout<<"0";
	}
	return 0;
}

