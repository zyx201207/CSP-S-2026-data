#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,c[200005],q=0,j,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		c[i]=a;
		if(i==1){
			j=a;
		}
		if(i==n){
			k=a;
		}
	}
	if(j+k==n){
		cout<<n-m;
		return 0;
	}
	sort(c+1,c+n+1);
	cout<<c[n-m+1];
	return 0;
} 
