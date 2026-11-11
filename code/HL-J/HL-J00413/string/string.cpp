#include<bits/stdc++.h>
using namespace std;
int a[999999];
char b[999999];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int l=0,r=n-1;
	for(int i=0;i<n;i++){
		int a1;char b1;
		cin>>a1>>b1;
		a[i]=a1;b[i]=b1;
	}
	long long ans=0;
	while(l<=r){
			int x=0;bool y=0;
			x=min(a[l],a[r]);
			if(b[l]!=b[r])y=1;
			a[l]-=x;
			a[r]-=x;
			if(a[l]<=0)l++;
			if(a[r]<=0)r--;
		if(l>r)break;
		if(y){
			ans+=x;
		}
	}cout<<ans;
	return 0;
}

