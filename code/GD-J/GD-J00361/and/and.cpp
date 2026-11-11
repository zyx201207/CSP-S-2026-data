#include<bits/stdc++.h>
#include<cstdio>
using namespace std; 
int index=1,n,m,a[200005],cnt,ans=0xffff;
int maxa=-1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,greater<int>());
	ans=a[1];
	for(int i=1;i<m;i++){
		maxa=-1e9;
		for(int j=index+1;j<=n-m+i+1;j++){
			if((ans&a[j])>maxa){
				maxa=(ans&a[j]);
				index=j;
			}
		}
		ans=maxa;
	}cout<<ans;
	return 0;
}
