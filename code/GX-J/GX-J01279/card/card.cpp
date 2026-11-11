#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],v[100005],ans[100005],b[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    v[a[i]]++;
	    b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
	    for(int j=i+1;j<=n;j++){
	        if(a[j]==a[j-1]){
	            v[a[j-1]]--;
	        }
	    }
	    b[a[i]]--;
	    for(int j=1;j<=m;j++){
	        if(v[j]>0) ans[j]++;
	        v[j]=b[j];
	    }
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
