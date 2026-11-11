#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],ma=-998244353;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	else if(m==2){
		int ma2=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				ma2=max(ma2,a[i]&a[j]);
			}
		}
		cout<<ma2;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else{
		cout<<ma;
	} 
	return 0;
}

