#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long a[200005],sum;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1;
	r=n;
	while(l<r){
		int x=min(a[l],a[r]);
		if(c[l]!=c[r]){
			sum+=x;
		}
		a[l]=a[l]-x;
		a[r]=a[r]-x;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<sum;
	fclose(stdin);fclose(stdout);
	return 0;
} 
