#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
			int x=a[i]&a[j];
			maxn=max(maxn,x);
			}
		}
	}
	cout<<maxn;
	return 0;
}
