#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],cnt[1000005],ans[1000005],b[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cnt[m]=n;
	int s=m;
	for(int i=n-1;i>=1;i--){
	    if(a[i]!=a[i+1]){
	    	m-=1;
	    	cnt[m]=i;
		}
	}
	for(int i=1;i<=s;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
