#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
long long n,m,a[N],ans=-1,d[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=1;
	}
	for(int k=31;k>=0;k--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!d[i])continue;
			if((a[i]>>k)&1)cnt++;
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(!d[i])continue;
				if(!((a[i]>>k)&1))d[i]=0;
			}
		}else if(cnt==m){
			for(int i=1;i<=n;i++){
				if(!d[i])continue;
				if((a[i]>>k)&1){
					if(ans==-1)ans=a[i];
					else ans=ans&a[i];
				}
				cout<<ans;
				return 0;
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(!d[i])continue;
		res++;
		if(ans==-1)ans=a[i];
		else ans=ans&a[i];
		if(res==m)break;
	}
	cout<<ans;
	return 0;
}
