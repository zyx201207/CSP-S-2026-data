#include <bits/stdc++.h>
using namespace std;

int a[500000];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0,cnt=0,c=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			ans+=(a[i]-a[j]);
				}
				if(ans>m){
			cnt=i;
			break;
		}else if(ans==m){
			cnt=i-1;
			break;
					}
			
		}
		cout<<cnt;
	return 0;
}
