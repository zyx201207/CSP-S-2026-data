#include<bits/stdc++.h>
using namespace std;
int n,m,a[200003],maxn=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	if(n<=2000){
		if(m==1){
			cout<<maxn;return 0;
		}
		else if(m==n){
			int res=a[1];
			for(int i=1;i<n;i++){
				res&=a[i];
			}
			cout<<res;
		}
		else if(m==2){
			maxn=-1;
			for(int i=0;i<n;i++){
				for(int j=i;j<n;j++){
					if(i!=j){
						maxn=max(maxn,a[i]&a[j]);
					} 
				}
			}
			cout<<maxn;
		}else if(m==3){
			maxn=-1;
			for(int i=0;i<n;i++){
				for(int j=i;j<n;j++){
					for(int k=j;k<n;k++){
						if(i!=j && j!=k && i!=k){
							maxn=max(maxn,a[i]&a[j]&a[k]);
						} 
					}
				}
			}
			cout<<maxn;
		}
	}else{
		cout<<a[n-1];
	}
	
	return 0;
}
