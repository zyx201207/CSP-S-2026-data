#include<bits/stdc++.h>
using namespace std;
int n,m;
long long w[100000005],ans;
char a,p[10000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>a;
		w[i]=m;
		p[i]=a;
	}
	int l=1,r=n,minn;
	while(1){
		if(r<=l) break;
		if(p[l]==p[r]){
			minn=min(w[l],w[r]);
			w[l]=w[l]-minn;
			w[r]=w[r]-minn;
			if(w[l]==0) l++;
			if(w[r]==0) r--;
		}
		if(p[l]!=p[r]){
			minn=min(w[l],w[r]);
			ans=ans+minn;
			w[l]=w[l]-minn;
			w[r]=w[r]-minn;
			if(w[l]==0) l++;
			if(w[r]==0) r--;
		}
	}
	cout<<ans;
	return 0;
}
