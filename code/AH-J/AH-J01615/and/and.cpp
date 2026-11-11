#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m,n,h=1;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		h=(h&a[i]);
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1]<<endl;
		return 0;
	}
	if(m==n){
		cout<<h<<endl;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=0;i<n;i++){
		    for(int j=i+1;j<n;j++){
		    	ans=max(ans,a[i]&a[j]);
			}
	    }
	    cout<<ans<<endl;
	    return 0;
	}
	if(m==n-1){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j==i) continue;
				h=h&a[j];
			}
			ans=max(ans,h);
			h=1;
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
