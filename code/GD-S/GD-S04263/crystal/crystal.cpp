#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans;
int main(){
	//freopen("crystal","r",stdin);
	//freopen("crystal","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=a[1],r=a[n];
	long long x=0;
	while(l<r){
		x=0;
		int mid=(l+r)/2;
		for(int i=1;i<=n;i++){
			if(a[i]<mid)x+=mid-a[i];
		}
		if(x>=m)r=mid;
		else l=mid+1;
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=l)ans++;
	}
	cout<<ans;
	return 0;
}
