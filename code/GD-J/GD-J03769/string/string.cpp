#include<bits/stdc++.h>
using namespace std;
int a[200001];
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		x=min(a[l],a[r]);
		if(c[l]!=c[r])sum+=x;	
		a[l]-=x;
		a[r]-=x;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<sum;
	return 0;
} 
