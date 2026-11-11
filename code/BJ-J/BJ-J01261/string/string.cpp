#include<bits/stdc++.h>
using namespace std;
int main{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,c=0;
	int cnt[300000],a[200000],sum[200000];
	for(int i=0;i<n;i++){
		cin>>cnt[i]>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=cnt[i];i++	{
			sum+=[a[i]];	
		}
	}
	int b=sum.lenth();
	for(int i=0;i<b;i++){
		for(int j=b;j>=0;j--){
			if(sum[i]!=sum[j]){
				sum[j]=sum[i];
				c++;			
		}
	}
	cout<<c;
	return 0;
}
	