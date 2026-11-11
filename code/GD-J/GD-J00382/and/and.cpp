#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,ans,a[N];
bool k[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],k[i]=1;
	for(int i=29;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!k[j])continue;
			if((a[j]>>i)&1)cnt++;
		}
		if(cnt>=m){
			ans|=(1<<i);
			for(int j=1;j<=n;j++){
				if(!k[j])continue;
				if(((a[j]>>i)&1)^1)k[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
