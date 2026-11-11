#include<bits/stdc++.h>
using namespace std;
int n;
long long m,mm;
long long a[500005],b[500005];
int ans,maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		mm=m;
		maxn=1;
		for(int j=1;j<=i;j++)b[j]=a[j];
		for(int j=i-1;j>=1;j--){
			if(mm<=0)continue;
			while(b[j]!=b[i]){
				b[j]++;
				mm--;
			}
			if(b[j]==b[i]&&mm>=0)maxn++;
		}
		ans=max(ans,maxn);
	}
	cout<<ans;
	return 0;
} 
