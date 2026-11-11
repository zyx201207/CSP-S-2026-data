#include<bits/stdc++.h>
using namespace std;

int n,m,sum=1;
int a[1000005],b[1000005],c[1000005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			b[i]+=c[j];
		}
		if(m>=b[i]){
			sum=max(i+1,sum);
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
