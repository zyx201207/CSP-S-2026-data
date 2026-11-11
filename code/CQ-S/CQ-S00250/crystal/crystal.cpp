#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	int f=0;
	int a[500005]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0){
			f++;
		} 
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		if(abs(a[1]-a[2])<=m){
			cout<<2;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	sort(a+1,a+n+1);
	int ans=0,sum;
	for(int i=1;i<=n;i++){
		if(f!=0){
			sum=0;
			for(int k=1;k<=f;k++){
				sum+=(i-a[i]);
				if(sum>m){
					ans=max(ans,k-1);
					break;
				}
			}
		}
		else{
			if(a[1]>i){
				
			}
			else{
				sum=0;
				for(int k=1;k<=(n+1)/2;k++){
					sum=sum+(i-a[i]);
					if(sum>m){
						ans=max(ans,k-1);
						break;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

