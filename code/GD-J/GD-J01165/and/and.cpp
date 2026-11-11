#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+8;
int n,m,a[maxn];

int main(){
	freopen("and3.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	//第一到五个测试点
	if(n<=20) {
		int ans=0;
		for(int i=0;i<(1<<n);i++){
			int take=0,k=i,res=0;
			for(int j=n;j>=0;j--){
				if(k>=(1<<j)){
					take++;
					if(take==1) res=a[j];
					else res=(res&a[j]);
					k-=(1<<j);
				}
			}
			if(take==m) ans=max(ans,res);
		}
		cout<<ans<<endl;
		return 0;
	}
	//第六个测试点 
	if(m==1){  
		int ans=0;
		for(int i=0;i<n;i++) ans=max(ans,a[i]);
		cout<<ans<<endl;
		return 0;
	}
	//第七个测试点
	if(m==n){
		int res=a[0];
		for(int i=1;i<n;i++) res&=a[i];
		cout<<res;
	}
	//第八到十个测试点 
	if(m==2){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if((a[i]&a[j])>ans) ans=(a[i]&a[j]);
			} 
		}
		cout<<ans;
	}
	return 0;
}
