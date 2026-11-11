#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m; cin >> n >> m;
	long long arr[500010];
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	sort(arr+1,arr+1+n);
	int mx=0;
	for(int i=1;i<=n;i++){
		int tmp=m,x=-1;
		for(int j=i;j>=1;j--){
			if(i-j<=tmp){
				tmp-=i-j;
				x=j;
			}
			else break;
		}
		mx=max(mx,i-x+1);
	}
	cout << mx;
	
	
	return 0;
}
