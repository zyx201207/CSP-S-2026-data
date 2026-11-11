#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m;
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(a[i],maxn);
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		int s=a[1];
		for(int i=2;i<=n;i++){
			s=s&a[i];
		}
		cout<<s;
		return 0;
	} 
	if(m==2){
		int k=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					k=max(k,a[i]&a[j]);
				}
			}
		}
		cout<<k;
	}
	 
	
	
	return 0;
} 
