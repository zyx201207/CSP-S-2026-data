#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500055],ans=1,q,l=1;
int main(){
	freopen("crystal.in","r",stdin);
  	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int r=2;r<=n;r++){
		q+=(r-l)*(a[r]-a[r-1]);
		if(q>m){
			while(q>m){
				long long p=a[r]-a[l];
				q-=p;
				l++;
			}
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
