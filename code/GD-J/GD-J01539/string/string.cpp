#include<bits/stdc++.h>
using namespace std;
int n,a[200001],s,s1;
string b[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(b[i]==b[i-1])s++;
		if(a[i]==1)s1++;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(s==n-1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<min(a[1],a[2]);
		return 0;
	}
	return 0;
}
