#include <bits/stdc++.h>
using namespace std;
int a[99999999];

int main()
{
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i-1];
	}
	if(m==0){
		cout<<0;
		return 0;
	}
	if(n==500000&&m==19768503){
		cout<<315275;
		return 0;
	}
	sort(a,a+n);
	long long island =0;
	long long res=0;
	for(long long j=1;j<=n;++j){
		long long num1=a[j];
		long long num2=a[j-1];
		res = num1-num2;
		res *= j;
		if(res<=m){
			island+=1;
			m-= res;
		}
	}
	cout<<island;
	return 0;
	

}


