#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200020],b[200020],ma=-114514;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		b[a[i]]++;
		ma=max(ma,a[i]);
	}
	for(int i=ma;i>=1;i--){
		if(b[i]>=m){
			cout<<i;
			return 0;
		} 
	}
	return 0;
}

