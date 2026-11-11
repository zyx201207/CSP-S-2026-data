#include<bits/stdc++.h>
using namespace std;
int n,m,ans,sum=1;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			int ans=max(ans,a[i]);
		}
	}
	if(m==2){
	    for(int i=1;i<=n;i++){
	    	for(int j=i;j<=n;j++){
	    		int sum=a[i]&a[j];
	    		int ans=max(ans,sum);
			}
		}
	}
	return 0;
}
