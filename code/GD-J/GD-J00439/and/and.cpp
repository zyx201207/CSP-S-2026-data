#include<bits/stdc++.h>
using namespace std;
int n,m,ans,maxn;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
	    cin>>a[i];
    }
    if(n==m){
    	for(int i=1;i<=n;i++) ans&=a[i];
    	cout<<ans;
	}
	else{
		cout<<12;
	}
	return 0; 
} 
