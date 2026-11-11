#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N],bz;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++){
		bz=a[i];
		int res=0,k=m;
		for(int j=i;j<=n;j++){
			if(bz==a[j]){
				res++;
			}else{
				if(bz-a[j]<=k){
					k-=(bz-a[j]);
					res++;
				}else{
					break;
				}
			}
		}
		ans=max(res,ans);
	}
	cout<<ans;
	return 0;
}
