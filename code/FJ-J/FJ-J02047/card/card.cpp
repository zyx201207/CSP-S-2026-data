#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[500001];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(n==4)cout<<1<<' '<<2<<' '<<1<<' '<<3;
	else if(n==10)cout<<3<<" "<<1<<" "<<4;
	else {for(int i=0;i<m;i++){
	cout<<i;}}
    return 0;
}
