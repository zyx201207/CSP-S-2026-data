#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000){
		int b=0;
		for(int i=1;i<n;i++){
			int ans=m;int sum=1;
			for(int j=i;j<n;j++){
				if(ans>=(j-i+1)*(a[j+1]-a[j]))
				{
					ans=ans-(j-i+1)*(a[j+1]-a[j]);
					sum++;
				}
			}
			b=max(b,sum);
		}
		cout<<b;
	}
	else{
		int sum=1;
		for(int i=1;i<n;i++){
			if(m>=i*(a[2]-a[1]))
			{
				m-=i*(a[2]-a[1]);
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}