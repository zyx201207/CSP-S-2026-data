#include <bits/stdc++.h>
using namespace std;
int n,m,ma=0;
int a[200010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int maa=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int aa=a[i]&a[j];
				maa=max(maa,aa);
			}
		}
		cout<<maa;
		return 0;
	}if(m==n-1){
		int sum=0;
		for(int i=1;i<=n;i++){
			int ans=a[1];
			for(int j=2;j<=m;j++){
				if(i!=j)ans&=a[i];
			}
			sum=max(ans,sum);
		}
		cout<<sum;
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[m];
	
	return 0;
}
