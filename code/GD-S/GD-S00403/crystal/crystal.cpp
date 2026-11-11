#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ans;
int a[500050],b[500050];
bool vis[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	sort(b,b+n);
	for(int i=2;i<=n;i++){
		if(cnt==m) break;
		if(vis[b[i]]==0){
			cnt+=b[i];
			ans++;
			vis[b[i]]=1;
		}
		if(cnt>m){
			cnt-=b[i];
			ans--;
			for(int j=i-1;j>=1;j--){
				cnt+=b[j];
				ans++;
				if(cnt==m) break;
				if(cnt>m){
					cnt-=b[j];
					ans--;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

