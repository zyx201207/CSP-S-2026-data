#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=0;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=max(ans,(a[i]&a[j]));
			}
		}
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
	}else{
		sort(a+1,a+1+n,greater<int>());
		ans=a[m];
	}
	cout<<ans;
	return 0;//誓死效忠绝区0!!! 挽昼大人万岁!!!
}
