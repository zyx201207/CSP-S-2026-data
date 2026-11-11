#include<bits/stdc++.h>
using namespace std;
long long a[200050];
char c[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0; 
	int l=1,r=n;
	while(l<r){
		long long minn=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=minn;
		}
		a[l]-=minn;
		a[r]-=minn;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<ans;
	return 0;
}
