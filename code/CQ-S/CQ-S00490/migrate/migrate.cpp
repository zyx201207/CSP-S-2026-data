#include<bits/stdc++.h>
using namespace std;
long long a[500005],pr[500005],nt[500005],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
int c,t;cin>>c>>t;
while(t--){
	int n,d;cin>>n>>d;
	a[0]=-4e18;
	for(int i=1,l=0;i<=n;i++){nt[i]=1e9;
		cin>>a[i];
		while(a[l]<a[i]-d)l++;
		pr[i]=l;nt[l]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			long long cnt=0,res=0;
			long long o=j,g=0;
			for(;o>i&&pr[o]!=o;o=pr[o])cnt++,g=o;
			if(o>i&&pr[o]==o)break;
			for(long long l=i,r=i;l<=j&&r<=j;){
				if(r<l)res+=l-r;
				l=nt[l];
				if(r==i) r=g;
				else r=nt[r];
			}
			if(res==1)ans++;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}

