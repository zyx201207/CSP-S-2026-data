//GZ-J00526 袁金厚 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,k,ans;
long long a[200050];
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(long long i=1;i<=(1LL<<n);i++){
		k=0;
		for(int j=0;j<n;j++){
			if(i&(1LL<<j)){
				k++;
				if(k==1)sum=a[j];
				if(k>1)sum=(sum&a[j]);
				if(k>m)break;
			}
		}
		if(k!=m)continue;
		ans=max(ans,sum);
	}
	cout<<ans<<"\n";
		return 0;
} 
