#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r".stdin);
	freopen("crystal.out","w".stdout);
	int n,m;cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		int sum=m;
		for(int j=1;j<=i;++j){
			int x=a[i-]
			sum-=s[i];
			if(sum<0){
				cout<<i-1;
				return 0;
			}
		}
		
	}
	cout<<n;
	return 0;
}
