#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxn=-999;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int cnt=a[i];
		for(int j=1;j<=m;j++){
			cnt=cnt&a[i+j];
			if(cnt>=maxn){
				maxn=cnt;
			}
		}
	}
	cout<<maxn;
	return 0;
	
}
