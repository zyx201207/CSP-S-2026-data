#include<bits/stdc++.h>
using namespace std; 
const int N=2e5+5,B=29;
int a[N],ans;
bool used[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)used[i]=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=B;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!used[j])continue;
			if(a[j]>>i&1)cnt++;
		}
		if(cnt>=m){
			ans|=(1<<i);
			for(int j=1;j<=n;j++){
				if(!used[j])continue;
				if(!(a[j]>>i&1))used[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
