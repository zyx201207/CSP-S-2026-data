#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a1[200005],a2[200005],ans=-0x3f,x,z,max1;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int p=1; p<=n; p++){
    	scanf("%lld",&a1[p]);
	}
	for(int p=1;  p<=n; p++){
		for(int i=p+1; i<=n; i++){
			if(ans<(a1[p]&a1[i])){
				x=p,z=i;
				ans=a1[p]&a1[i];
			}
		}
	}
	a2[2]=ans;
	for(int p=3; p<=m; p++){
		int u=0;
		for(int i=1; i<=n; i++){
			if(u!=0 && i!=z && i!=x) a2[p]=max(a2[p],a2[p-1]&a1[i]);
			else if(i!=z && i!=x) a2[p]=a2[p-1]&a1[i],u=1;
		}
	}
	printf("%lld",a2[m]);
	return 0;
}
