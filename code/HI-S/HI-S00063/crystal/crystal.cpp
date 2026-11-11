#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int n,m,b,cnt=0,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b;
		a[i]=b;
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=1;j<=i;j++){
			cnt+=a[j];
		}
		for(int j=1;j<=m;j++){
			if(cnt%a[i]==0){
				ans=max(ans,cnt/a[i]);
				break;
			}
			cnt++;
		}
	}
	cout<<ans;
	return 0;
}

