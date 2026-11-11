#include<bits/stdc++.h>
using namespace std;
long long n,m,a,s[500005],la=0;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		s[a]++;
	}
	la=a;
	for(int i=1;i<=m;i++){
		if(i==la)cout<<n;
		else cout<<s[i];
		cout<<" ";
	}
	return 0;
}
