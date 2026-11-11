#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200001],ans,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[1];
	sum=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		sum=(sum&a[i]);
	}
	if(n==m){
		cout<<sum;
		return 0;
	}else{
		if(n==1){
			ans=a[1];
		}else{
			ans=-1;
		}
	    for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
			    ans=max(ans,(a[i]&a[j]));
		    }
	    }
	    cout<<ans;
	}
	return 0;
}
