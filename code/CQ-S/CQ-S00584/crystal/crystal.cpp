#include<bits/stdc++.h>
using namespace std;

long long a[1000005];
long long n,m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	sort(a+1,a+n+1);
	int sum=1;
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			if(a[j]-a[i]<=m){
				m-=a[j]-a[i];
				a[i]+=a[j]-a[i];
				break;
			}
		}
	}
	for(int j=2;j<=n;j++){
		if(a[j]==a[1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
