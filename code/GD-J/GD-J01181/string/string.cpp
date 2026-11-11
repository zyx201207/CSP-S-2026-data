#include<bits/stdc++.h>
using namespace std;
int n,a[200005],l=1,r;
long long sum=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(l<r){
		if(c[l]==c[r]){
			int m=min(a[l],a[r]);
			a[l]-=m,a[r]-=m;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
		else{
			int m=min(a[l],a[r]);
			a[l]-=m,a[r]-=m;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
			sum+=m;
		}
	} 
	cout<<sum;
	return 0;
} 
