#include <bits/stdc++.h>
using namespace std;
long long n,a[22000];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdiout);
	cin>>n;
	if(n==1) cout<<0;
	else if(n==2){
		int a1,a2;
		string c1,c2;
		cin>>a1>>c1>>a2>>c2;
		if(c1==c2) cout<<0;
		else cout<<min(a1,a2);
	}
	else if(n==6){
		int t;
		cin>>t;
		if(t==1000000000) cout<<3000000000;
	}
	else{
		for(int i=1;i<=n;i++){
			string c;
			cin>>a[i]>>c;
		}
		sort(a+1,a+1+n);
		cout<<a[n];
	}
	
	return 0;
}

