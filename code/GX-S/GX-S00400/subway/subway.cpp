#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q,k;
int w[100005],a[100005],t[100005],x[100005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int p=0;p<m;p++){
		cin>>w[p];}
	for(int p=0;p<n;p++){
		cin>>k;
		for(int pp=0;pp<k;pp++){
			cin>>a[pp]>>t[pp];}}
	return 0;}
