//GZ-J00248 贵阳市南明区华麟学校 杨瑞泽 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++) ans=max(ans,a[i]|a[j]);
	}
	cout<<ans;
	return 0;
}
