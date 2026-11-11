#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=-1,minn=1e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>maxx){
				maxx=a[i];
			}
		}
		cout<<maxx;
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]<minn){
				minn=a[i];
			}
		}
		cout<<minn;
	}
	return 0;
} 
