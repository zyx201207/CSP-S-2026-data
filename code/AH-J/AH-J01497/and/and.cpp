#include<bits/stdc++.h>
#define int long long
using namespace std;
int v[222222];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
	if(m==1){
		int max=0;
		for(int i=1;i<=n;i++){
		    cin>>v[i];
		    if(max<v[i]) max=v[i];
	    }
	    cout<<max;
	}else if(m==n){
		int ans=0;
		for(int i=1;i<=n;i++){
		    cin>>v[i];
		    if(i==1)ans=v[i];
		    else ans=ans&v[i];
	    }
	    cout<<ans;
	}else{
		int max1=0,max2=0;
		for(int i=1;i<=n;i++){
		    cin>>v[i];
		    if(v[i]>max1){
				max2=max1;
				max1=v[i];
			}
	    }
	    int u=max2&max1;
	    cout<<u;
    }
    return 0;
}
