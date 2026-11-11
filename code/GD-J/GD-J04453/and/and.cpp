#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
//	freopen("and.out","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		long long mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]); 
		}
		cout<<mx;
	}else if(m==n){
		long long mx=a[1];
		for(int i=2;i<=n;i++){
			mx=mx&a[i];
		}
		cout<<mx;
	}else if(m==2){
		long long mx=0;
		for(int i=1;i<n;i++){
			mx=max(mx,a[i]&a[i+1]);
		}
		cout<<mx;
	}else{
		long long mx=0;
		for(int i=1;i<=n-m+1;i++){
			long long ans=a[i];
			for(int j=i+1;j<i+m;j++){
				ans=ans&a[j];
			}
			mx=max(mx,ans);
		}
		cout<<mx;
	}
	return 0;
}
