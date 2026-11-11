#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int b[500005],c[500005];
int ans,res,id,w;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
//    	cin>>a[i];
    	b[i]=a[i]-a[i-1];
    	c[i]=c[i-1]+b[i];
    	res=ans+b[i]*(i-w-1);
//    	ans+=b[i]*i;
//		cout<<res<<' ';
    	if(res>m){
    		int j=w+1;
    		while(res>m){
    			res-=a[i]-a[j];
    			w++;
    			j++;
			}
		} 
    	ans=res;
    	id=max(id,i-w);
//    	cout<<ans<<' '<<id<<' '<<w<<endl;
	}
	cout<<id;
    return 0;
}

