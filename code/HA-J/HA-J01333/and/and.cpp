#include <bits/stdc++.h>
using namespace std;
int a[200005];
int r[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(1){
		r[n]++;
		int k=0,t=0;
		for(int i=n;i>=1;i--){
			if(r[i]==1) k++;
			if(r[i]==2){
				r[i]=0;
				r[i-1]++;
			}
		}
		if(r[0]) break;
		if(k==m){
			for(int i=1;i<=n;i++){
				if(r[i]){
					if(t==0){
						t=a[i];
					}else{
						t=t&a[i];
					}
				}
			}
		}
		ma=max(ma,t);
	}
	cout<<ma;
	return 0;
}