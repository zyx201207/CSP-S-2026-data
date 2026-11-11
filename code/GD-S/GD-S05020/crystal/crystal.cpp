#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0,flag=1,x;
int ans=1;
long long a[500005],s[5005][5005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2){
			x=a[2]-a[1];
			if(a[i]-a[i-1]!=x) flag=0;
		}
	}
	if(flag){
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum+=i*x;
			if(sum>m){
				cout<<i<<"\n";
				return 0;
			}
		}
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j;k++){
				s[i][j]+=j-k;
			}
			if(s[i][j]>m)continue;
			else ans=max(ans,j-i+1);
		}
	}
	cout<<ans<<'!'<<"\n";
	
	
	
	return 0;
} 
