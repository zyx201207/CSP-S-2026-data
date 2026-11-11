#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[500005],b[500005],ans=0,c=1;
	a[0]=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
	    b[i-1]=a[i]-a[i-1];
	}
	sort(b,b+n-1);
	for(int i=0,j=1;i<n-1;i++){
		c=1;j=i+1;
		while(b[j]!=b[i]&&j<=n-1){
			 c++;
			 j++;
		}
		ans=max(ans,c);
    }
    if(ans>m)ans=m;
    cout<<ans;
}
