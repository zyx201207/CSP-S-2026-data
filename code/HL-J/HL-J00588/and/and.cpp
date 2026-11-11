#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxk=0,sumk=INT_MAX;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxk=max(maxk,a[i]);
		sumk&=a[i];
	}
	if(n<=20){
		int maxn=0;
		for(int js=0;js<(1<<n);js++){
			int cnt=0,sum=(1<<22)-1;
			for(int i=1;i<=n;i++){
				if(js&(1<<(i-1))){
					cnt++;
					sum&=a[i];
				}
			}
			if(cnt!=m)continue;
			maxn=max(maxn,sum);
		}
		cout<<maxn;
		return 0;
	}else if(m==1){
		cout<<maxk;
		return 0;
	}else if(m==n){
		cout<<sumk;
		return 0;
	}else if(m==2){
		int maxls=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				maxls=max(maxls,a[i]&a[j]);
			}
		}
		cout<<maxls;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}
