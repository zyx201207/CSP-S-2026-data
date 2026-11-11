#include<bits/stdc++.h>
using namespace std;
int a[200005],maxn=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1){
		cout<<0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int b=a[i]&a[j];
			maxn=max(maxn,b);
		}
	}
	
	cout<<maxn;
	return 0;
}
