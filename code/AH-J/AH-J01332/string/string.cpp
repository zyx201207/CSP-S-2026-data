#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,cnt;
int a[200005];
char b[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
	    cin>>a[i];
		cin>>b[i];
	    ans+=a[i];
	}
	int l=a[1],r=a[n],x=1,y=n;
	while(l<=ans/2+1&&r<=ans/2+1){
		if(l>=r&&b[x]!=b[y])cnt+=r-max(l-a[x],r-a[y]);
		if(l>=r)r+=a[--y];
		if(l<r&&b[x]!=b[y])cnt+=l-max(l-a[x],r-a[y]);
		if(l<r)l+=a[++x];
	} 
	cout<<cnt;
	return 0;
}
