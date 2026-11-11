#include<bits/stdc++.h>
using namespace std;
int j,n,a[200001];
long long ans;
char c[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    int d=0,e=0;
    for(int i=1;i<=(n/2+1);i++){
		j=n-i+1+e;
		i-=d;
		d=0,e=0;
		int t=min(a[i],a[j]);
		a[i]-=t;
		a[j]-=t;
		if(a[i]==0) e=1;
		if(a[j]==0) d=1;
		if(a[i]==0&&a[j]==0) d=0,e=0;
		if(c[i]!=c[j]) ans+=t;
	}
    cout<<ans;
    return 0;
}
