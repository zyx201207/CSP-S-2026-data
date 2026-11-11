
#include<bits/stdc++.h>
using namespace std;
int n,b,sum,num;
int a[1000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=a[n]&a[n-1];
	sum=ans;
	for(int i=n;i>=1;i--){
		for(int j=3;j<=b;j++){
			if(i-j<0){
				cout<<num;
				return 0;
			}
			sum&=a[i-j];
		}
		num=max(num,sum);
		sum=a[i-b];
	}
	cout<<sum;
	return 0;
}
