#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l,r,d;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	l=1,r=n;
	while(l<r){
		if(c[l]!=c[r])d+=min(a[l],a[r]);
		if(a[l]==a[r])l++,r--;
		else if(a[l]>a[r])a[l]-=a[r],r--;
		else a[r]-=a[l],l++;
	}
	cout<<d;
	return 0;
} 
