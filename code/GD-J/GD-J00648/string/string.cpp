#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long sum,ans,n,a[N];
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	long long k=sum/2,dt=1,dl=n,minn;
	while(k>0){
		if(a[dt]<=k){
//			cout<<dt<<"  1\n";
			while(a[dt]>0){
				minn=min(a[dt],a[dl]);
				if(s[dt]==s[dl]){
					a[dt]-=minn,a[dl]-=minn;
				}
				else if(s[dt]!=s[dl]){
					a[dt]-=minn,a[dl]-=minn,ans+=minn;
				}
				k-=minn;
				if(a[dl]==0) dl--;
			}
			dt++;
//			cout<<dt<<" "<<dl<<" "<<ans<<"\n";
		}
		else{
//			cout<<dt<<"  2\n";
			while(a[dt]>k){
				if(s[dt]==s[dl]) minn=min(min(a[dt],a[dl]),k),a[dt]-=minn,a[dl]-=minn;
				else minn=min(min(a[dt],a[dl]),k),a[dt]-=minn,a[dl]-=minn,ans+=minn;
				k-=minn;
				if(k==0) break;
				if(a[dl]==0) dl--;
			}
//			cout<<dt<<" "<<dl<<" "<<ans<<"\n";
		}
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
