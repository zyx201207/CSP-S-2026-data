#include<bits/stdc++.h>
using namespace std;
int n,m,a[2010],minn=0x3f3f3f,maxn=0;
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+1+n);
	if(m==n){
		cout<<minn;
		return 0;
	}
	if(m==1){
		cout<<maxn;
	}else if(m==n-1){
		cout<<a[2];
	}else{
		cout<<a[n-1];
	}
	return 0;
}
