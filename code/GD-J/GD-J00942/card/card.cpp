#include<bits/stdc++.h>
using namespace std;
#define int long long
#define File(x) (freopen(x".in","r",stdin),freopen(x".out","w",stdout))
const int N=1e6+5,mod=1e9+7;
int n,m;
int a[N],lst[N];
int ans[N];
signed main(){
	File("card");
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],ans[a[i]]++,lst[a[i]]=i;
	for(int i=1;i<=n;i++)
		if(lst[a[i]]==i)ans[a[i+1]]+=ans[a[i]];
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}