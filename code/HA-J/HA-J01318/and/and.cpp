#include<bits/stdc++.h>
using namespace std;

int n,m,a[99999];
int ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
		    int b=a[i] and a[j];
		    ans=max(ans,b);
		}
	}
    cout<<ans;
	return 0;
}
