#include<bits/stdc++.h>

using namespace std;

int n,m,s;
long long a[500007];
long long d[500007];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		//cout<<i<<" "<<a[i]<<endl;
	}
	
	long long l=1,ans=0;
	for(int i=2;i<=n;i++){
		s+=d[i]*(1LL*i-l);
		if(s>m){
			ans=max(ans,1LL*i-l);
			s=0,l=i;
		}
	}
	
	cout<<ans;
		
	return 0;
}

// A: 应该可以的
// B: 考虑到可以从中间截取 
