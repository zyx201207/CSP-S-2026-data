#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+7;
int n,a[maxn];
char b[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int ans=0;
	for(int i=0,j=n;i<j;){
		if(b[i]!=b[j]){
			ans+=min(a[i],a[j]);
		}
		if(a[i]<a[j]){
			a[j]-=a[i];
			i++;
		}else if(a[i]>a[j]){
			a[i]-=a[j];
			j--;
		}else{
			i++;j--;
		}
	}
	cout<<ans;
	return 0;
}
