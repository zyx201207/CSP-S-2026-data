#include<bits/stdc++.h>
#define int long long
using namespace std;
const int hxy=5e5+7;
int a[hxy],b[hxy],n,m,j,k,l,c,d,x,y,ans,sum;
main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)c=1;
	}
	if(c==0){
		d=0;
		for(int i=1;i<=5e5;i++){
			if(i*(i+1)/2>m){
				d=i;
				break;
			}
		}
		if(d==0)cout<<n;
		else cout<<d;
		return 0; 
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans=m;
		sum=0;
		for(int j=i;j>=1;j--){
			y=a[i]-a[j];
			sum++;
			if(ans-y<=0)break;
			ans-=y;
		}
		x=max(x,sum);
	}
	cout<<x;
} 
