#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ma=0;
	for(int i=2;i<=n;i++){
		int sum=0;
		for(int j=i;j>=1;j--){
			sum+=(a[i]-a[j]);
			if(sum<=m)ma=max(ma,i-j+1);
			else break;
		}
	}
	cout<<ma;
	return 0;
} 
