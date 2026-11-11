#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],ai;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>ai;
		a[ai]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]+1<<' ';
	}
	return 0;
}
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
