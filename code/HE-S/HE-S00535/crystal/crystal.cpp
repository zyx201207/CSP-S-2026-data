#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long a[N],m,n,op,op1,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==0){
		op=(a[n/2]+a[n/2+1])/2;
		op1=n/2;
	}
	else{
		op=a[n/2+1];
		op1=n/2+1;
	}
	while(m){
		while(a[op1-1]!=op){
			m--;
			a[op1-1]++;
		}
		op1--;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==op) ans++;
	}
	cout<<ans;
	return 0;
}
