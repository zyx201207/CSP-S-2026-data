#include<bits/stdc++.h>
using namespace std;
int t[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5],b[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	    int l=1,r=i;
	    while(r<=n){
		    b[l]=a[r];
		    if(t[b[l]]==1){
		       int x=l;
		       l--;
			   while(b[l]!=b[x]){
			   	    ans[b[l]]--;
			   	    t[b[l]]=0;
			   	    l--;
			   }
		    }else{
			   t[b[l]]=1;
			   ans[b[l]]++;
		    }
		    l++;
	    	r++;
	    }
		for(int j=1;j<=m;j++){
			t[j]=0;
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
