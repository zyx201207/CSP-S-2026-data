#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int ans=0,n,m,a[100005],del[100005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		del[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++){
		int x=1,sum=0;
		while(sum+x*del[i-x]<=m){
			if(i-x<1)break;
			sum+=x*del[i-x];
			x++;
		}
		int same=-1;
		for(int j=1;j<=n;j++){
			if(a[j]==a[i])same++;
		}
		ans=max(ans,x+same);
	}
	cout<<ans;
	return 0;
}