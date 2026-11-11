#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long he[500005];
int ans=1;
long long cost;
long long n,m;
int last=1;
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	
	he[0]=0;
	he[1]=a[1];
	for(int i=2;i<=n;i++){
		he[i]=he[i-1]+a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=max(last,i);j<=n;j++){
			cost=(j-i+1)*a[j]-(he[j]-he[i-1]);
			if(cost>m){
				ans=max(j-i,ans);
				last=j-1;
				break;
			}
		}
	}

	cout<<ans;
	return 0;
}
