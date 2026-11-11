#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],r,cnt;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		long long x=min(a[l],a[r]);
		if(c[l]!=c[r]){
			cnt+=x;
		}
		a[l]-=x;
		a[r]-=x;
		if(a[l]<=0)l++;
		if(a[r]<=0)r--;
		//cout<<cnt<<" ";
	} 
	cout<<cnt;
	return 0;
} 
