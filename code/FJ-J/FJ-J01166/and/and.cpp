#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],flag[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		flag[i]=1;
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(flag[j]&&((a[j]>>i)&1))cnt++;
		}
		if(cnt>=m){
			ans|=(1<<i);
			for(int j=1;j<=n;j++){
				if(!((a[j]>>i)&1))flag[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
