#include<bits/stdc++.h>
using namespace std;
int a[10002];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxx;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}
	if(m==n){
		int ans=0;
		for(int i=1;i<=n;i++)ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		long long ans,maxx;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i)ans&=a[j];
			}
			maxx=max(ans,maxx);
		}
		cout<<maxx<<endl;
		return 0;
	}
	/*if(n<=20){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				
			}
		}
	}*/
	sort(a+1,a+n+1,cmp);
	cout<<a[m]<<endl;
	return 0;

}

