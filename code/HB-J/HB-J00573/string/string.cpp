#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char zs[10000005];
	int n,sum=1,ans=0;
	cin>>n;
	for(int t=1;t<=n;t++){
		int a;
		char s;
		cin>>a>>s;
		for(int i=sum;i<=a;i++) zs[i]=s;
		sum+=a;
	}
	sum-=1;
	for(int l=1;l<=sum/2;l++){
		int r=sum-l;
		if(zs[l]!=zs[r]) ans++;
	}
	cout<<ans;
	return 0;
}
