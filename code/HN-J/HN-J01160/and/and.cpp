#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],m,b[1000000],cnt,c[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		cnt=a[1];
		for(int i=2;i<=n;i++) max(cnt,a[i]);
	}
	cout<<cnt;
	return 0;
}
