#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m; cin>>n>>m;
    int maxN=0,sum=0,maxI=0;
    for(int i=1; i<=n; i++){
    	cin>>a[i];
    	int t=i;
    	if(a[i]>=maxN) maxN=a[i];
    	sum&=a[i];
    	if(m==1){
    		cout<<maxN;
    		return 0;
		}
		if(m==n){
			cout<<sum;
			return 0;
		}
		if(m==2){
			for(int j=i; j<=n; j++){
				maxI=max(maxI,a[i]&a[j]);
			}
		}
	}
	cout<<maxI;
    return 0;
}