#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int num=0;
	for(int i=n;i>=1;i--){
		if(a[i-1]+m/(i-1)>=a[i]){
			for(int j=i-1;j>=1;j--){
				num=num-a[j]+a[i];
			}
			if(num<=m){
				cout<<i;
				return 0;
			}else{
				continue;
			}
		}
	}
	return 0;
}
