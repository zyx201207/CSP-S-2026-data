#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int s[N];	
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int maxn=-999;
	for(int i=1;i<n;i++){
		if(s[i] and s[i+1]>maxn)maxn=s[i] and s[i+1];
	}
	cout<<maxn;
	return 0;
} 
