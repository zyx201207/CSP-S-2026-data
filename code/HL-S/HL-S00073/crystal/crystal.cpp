#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],book;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);//from s to b
	long long tip=a[2]-a[1];
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=i;j++){
			a[j]+=tip;
			m-=tip;
			if(m<=0) break;
		}
		if(m<=0) break;
	}
	if(m<0) a[1]-=tip;
	long long num=a[1],ans=0;
	for(long long i=1;i<=n;i++){
		if(a[i]==num) ans++;
	}
	cout<<ans;
	return 0;
}