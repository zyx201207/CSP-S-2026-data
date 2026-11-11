#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],maxx;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n-m+1;i++){
    	int t=0;
    	t=a[i];
        for(int j=1;j<m;j++){
	        t&=a[i+j];
	    }
	    maxx=max(t,maxx);
    }
    cout<<maxx;

    return 0;
}
