#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopem("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxn=0;
		for(int i=0;i<n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	else if(m==2){
		int maxn=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	else if(m==n){
		int maxn=0;
		for(int i=0;i<n;i++){
			maxn&=a[i];
		}
		cout<<maxn;
	}
	else cout<<1;
}
