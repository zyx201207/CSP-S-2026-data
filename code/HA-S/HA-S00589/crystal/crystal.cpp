#include <bits/stdc++.h>
using namespace std;
//contianer
long long m,k,x;
int n,sum,ans;
long long a[500005];
//main
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		x = m;
		sum = 0;
		for(int j=i;j>=1;--j){
			if(x >= a[i] - a[j]){
				++sum;
				x -= a[i] - a[j];
			}else{
				break;
			}
		}
		ans = max(ans,sum);
	}
	cout<<ans;
	
	return 0;
}

