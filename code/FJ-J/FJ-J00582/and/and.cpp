#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t,ans,cnt,a[200005];
bool b[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	int t=1<<30;
	while(t){
		cnt=0;
		for(int i=0;i<n;i++)if(!b[i]&&((a[i]&t)>0))cnt++;
		if(cnt>=m){
			ans+=t;
			for(int i=0;i<n;i++)if((a[i]&t)==0)b[i]=1;
		}t/=2;
	}cout<<ans;
}
