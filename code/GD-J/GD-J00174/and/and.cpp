#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
long long ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=30;i>=0;i--){
		int cnt=0;
		for (int j=1;j<=n;j++){
			if ((1<<i)&a[j])cnt++;
		}
		if (cnt>=m){
			ans+=(1<<i);
			for (int j=1;j<=n;j++){
				if (!((1<<i)&a[j]))a[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
