#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=a[i]&b[i-1];
	}
	
	int j=m;
	for(int i=1;i<=n;i++){
		int ans=a[i];
		for(int t=i;t<=i+m-1;t++){
			ans=a[t] & ans;
			//cout<<ans<<" ";
		} 
		if(ans>sum) sum=ans;
	}
	cout<<sum;
	
	return 0;
	
}


	

