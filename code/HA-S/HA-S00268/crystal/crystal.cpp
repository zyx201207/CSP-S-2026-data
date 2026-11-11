#include <bits/stdc++.h>
using namespace std;
int n,a[500005],cnt,k;
unsigned long long m;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if((a[i]+a[i+1]+m)/2==a[i+2]){
			unsigned long long k=a[i+2];
			int u=i+2; 
			for(int j=u;j<=n;j++){
				if(a[j]==k){
					cnt++;
				}
				else{
					break;
				}
			}
			cout<<cnt+2;
			return 0;
		}
	}
	return 0;
} 
