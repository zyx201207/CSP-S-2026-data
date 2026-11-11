#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=0;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("strint.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
	    long long MinV=min(a[l],a[r]);
		if(c[l]!=c[r])sum+=MinV;
		a[l]-=MinV;
		a[r]-=MinV;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	} 
	cout<<sum;
	return 0;
}
