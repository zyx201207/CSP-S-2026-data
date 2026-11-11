#include<bits/stdc++.h>
using namespace std;
long long n,m,a,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a;
	sum=a;
	for(int i=2;i<=n;i++){
		cin>>a;
		sum=sum&a;
	}
	if(m==n) cout<<sum;
	return 0;
}
