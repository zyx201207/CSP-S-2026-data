#include<bits/stdc++.h>
using namespace std;
long long a[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	long long n,m,ans = 0,j,k;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(j = n-1;j>0;j--){
		if(a[j]-a[0]>=m){
			continue;
		}
		else{
			break;
			}
		}
	for(k = 0;k<j;k++){
		ans += a[j]-a[k];
		if(ans>m){
			cout<<k-1<<'\n';
			return 0;
		}
	}
	cout<<k+1<<'\n';
	return 0;
}
