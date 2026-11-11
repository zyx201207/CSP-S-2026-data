#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,a[200005],sum;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int mid=sum/2;
	for(int i=1,j=n,k=0;i<=n&&k<mid;){
		int minn=min(a[i],a[j]);
		if(i==j)break;
		if(c[i]!=c[j]){
			ans+=minn;
		}
		if(a[i]==minn)i++;
		else a[i]-=minn;
		if(a[j]==minn)j--;
		else a[j]-=minn;
		k+=minn;
	}
	cout<<ans;
	return 0;
}
