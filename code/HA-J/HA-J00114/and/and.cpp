#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
bool chs[N];
int ty(int num,int type){
	return (num>>type)-(num>>(type+1)<<1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int l=31;l>=0;l--){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(ty(a[i],l)&&!chs[i]){
				sum++;
			}
		}
		if(sum>=m){
			ans+=1<<l;
			for(int i=1;i<=n;i++){
				if(!ty(a[i],l)&&!chs[i]){
					chs[i]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
